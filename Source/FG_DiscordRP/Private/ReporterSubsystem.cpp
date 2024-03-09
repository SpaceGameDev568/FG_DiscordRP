// Copyright 2023 - 2024 Jesse Hodgson. All Rights Reserved.

#include "ReporterSubsystem.h"
#include "FG_DiscordRP.h"
#include "FGBlueprintFunctionLibrary.h"
#include "FGNetworkLibrary.h"
#include "FGPlayerController.h"
#include "FGLocalPlayer.h"
#include "FGPlayerControllerBase.h"
#include "FGAdminInterface.h"
#include "Languages/LangEnglish.h"
#include "GameFramework/GameMode.h"
#include "DRP_ConfigStruct.h"
#include "FGGameSession.h"
#include "GameFramework/GameSession.h"
#include "ModLoading/ModLoadingLibrary.h"
#include "Network/NetworkHandler.h"

AReporterSubsystem::AReporterSubsystem()
{
	UpdateInterval = 5.0f;
	NumPlayersInSession = 1;
	MaxPlayers = 4;
	PresenceString = "Session Loading...";
	TierString = "Session Loading...";
	DetailsString = "Session Loading...";
	StateString = "Session Loading...";
	GameLanguage = "Session Loading...";
	DiscordApplicationID = "1082738646173614143";
	DiscordObject = nullptr;

	// Initialize variables from config
	{
	#if WITH_EDITOR
	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Shipping env not detected, avoiding crash"));
	#else
	myConfig = FDRP_ConfigStruct::GetActiveConfig(GetWorld());
	#endif
	}

	EnableDebugLogging = myConfig.debug_logging;
	UpdateInterval = myConfig.update_interval;
	IsDeveloper = myConfig.is_developer;
}

// Initialize Subsystem
void AReporterSubsystem::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Loaded FG_DRP Reporter Subsystem."));

	FModInfo ModInfo;

	const UGameInstance* GameInstance = GetGameInstance();

	UModLoadingLibrary *ModLoadingLibrary = GameInstance->GetSubsystem<UModLoadingLibrary>();

	ModLoadingLibrary->GetLoadedModInfo("FG_DiscordRP", ModInfo);

	// Log the name and version of the mod
	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"), *ModInfo.Name.Append(", " + ModInfo.Version.ToString()));

	// Get the language for the interpreter to use later
	GameLanguage = UFGBlueprintFunctionLibrary::GetLanguage();
	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"), *GameLanguage);
	// Create and assign our DiscordObject to a variable
	UDiscordObject::CreateDiscordObject(DiscordApplicationID, false, true);
	DiscordObject = UDiscordObject::GetDiscordObject();

	// Log the value of our DiscordObject
	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"), *DiscordObject->GetName());

	// Check if our DiscordObject is valid or not before continuing
	if(IsValid(DiscordObject))
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Discord Object is valid."));
	}
	else
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Discord Object not valid, please report this error."));
	}

	// Set the session type to friends only
	APlayerController* PCRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("PCRef: %s"), *PCRef->GetName());

	AFGPlayerController* VarPlayerController = Cast<AFGPlayerController>(PCRef);

	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("VarPlayerController: %s"), *VarPlayerController->GetName());

	APlayerState* PlayerState = VarPlayerController->GetPlayerState<APlayerState>();

	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"), *PlayerState->GetPlayerName().Append(" has joined the server."));

	if(AFGAdminInterface* AdminInterface = VarPlayerController->GetAdminInterface())
	{
		// Make MaxPlayers count actually track the amount allowed by the server
		AFGGameSession* GameSession;

		//UCLASS(notplaceable)
		//class FACTORYGAME_API AFGAdminInterface : public AInfo
		//{
		//	GENERATED_BODY()
		//
		//	friend class AReporterSubsystem;

		// IF THIS ERRORS IN NEWER VERSIONS, ADD 'friend class AReporterSubsystem;' TO THE AREA ABOVE ON FGAdminInterface.h

		// Get the game session
		GameSession = AdminInterface->GetGameSession();

		// Get the amount of players allowed in the game session
		MaxPlayers = GameSession->MaxPlayers;

		AdminInterface->SetSessionVisibility(ESessionVisibility::SV_FriendsOnly);
	}

	FTimerHandle MemberTimerHandle;

	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AReporterSubsystem::ProcessPresenceString, UpdateInterval, true, UpdateInterval);
	// End Subsystem Initialization
}

// Get and process the local player presence string
void AReporterSubsystem::ProcessPresenceString()
{

	// Thanks to SirDigby for helping me with this
	auto player = Cast<UFGLocalPlayer>(this->GetWorld()->GetGameInstance()->GetFirstLocalPlayerController()->GetLocalPlayer());
	FPlayerPresenceState pState;

	//UCLASS(BlueprintType)
	//class FACTORYGAME_API UFGLocalPlayer : public ULocalPlayer
	//{
	//	GENERATED_BODY()
	//
	//	friend class AReporterSubsystem;

	// IF THIS ERRORS IN NEWER VERSIONS, ADD 'friend class AReporterSubsystem;' TO THE AREA ABOVE ON FGLocalPlayer.h
	player->GetPresenceState(pState);
	FString pString = pState.mPresenceString;

	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"),*pString);

	FString TierSplitOut;

	pString.Split(TEXT(":"), &TierString, &TierSplitOut);

	FString DetailsSplitOut;

	TierSplitOut.Split(TEXT("in"), &DetailsString, &DetailsSplitOut, ESearchCase::IgnoreCase, ESearchDir::FromEnd);

	FString StateSplitOutDISCARD;

	DetailsSplitOut.Split(TEXT("."), &StateString, &StateSplitOutDISCARD, ESearchCase::IgnoreCase, ESearchDir::FromEnd);

	bool TutorialException = false;

	if(GameLanguage == "en-US-POSIX" || GameLanguage == "en-CA" || GameLanguage == "en-GB"){
	ULangEnglish::InterpretEnglish(StateString, TierString, pString, DiscordObject, EnableDebugLogging, TutorialException);
	} else
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("This game language is not currently supported by the Discord Rich Presence mod: %s"), *GameLanguage);

		DiscordObject->SetLargeImage("satisfactory_logo");
		DiscordObject->SetLargeImageText("Satisfactory");
		DiscordObject->SetSmallImage("");
		DiscordObject->SetSmallImageText("");
	}

	// Get Player Count
	NumPlayersInSession = UGameplayStatics::GetGameMode(GetWorld())->GetNumPlayers();

	// Add a catch for if the player is currently in the tutorial phase
	if (TutorialException)
	{
		pString.Split(TEXT("."), &DetailsString, &StateString);
	}
	else if(IsDeveloper)
	{
		DiscordObject->SetState("ficsit.app/mod/FG_DiscordRP");

		DiscordObject->SetDetails("Developing this mod");
	}
	else
	{
		DiscordObject->SetState(StateString);

		DiscordObject->SetDetails(DetailsString);
	}

	DiscordObject->SetPartySize(NumPlayersInSession);

	DiscordObject->SetPartyMax(MaxPlayers);
}