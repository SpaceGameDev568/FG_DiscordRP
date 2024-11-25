// Copyright 2023 - 2024 Jesse Hodgson. All Rights Reserved.

#include "ReporterSubsystem.h"
#include "FG_DiscordRP.h"
#include "FGBlueprintFunctionLibrary.h"
#include "FGNetworkLibrary.h"
#include "FGPlayerController.h"
#include "FGLocalPlayer.h"
#include "FGPlayerControllerBase.h"
#include "FGAdminInterface.h"
#include "DiscordThumbnails.h"
#include "GameFramework/GameMode.h"
#include "DRP_ConfigStruct.h"
#include "FGGameSession.h"
#include "GameFramework/GameSession.h"
#include "ModLoading/ModLoadingLibrary.h"
#include "activity_manager.h"
#include "Kismet/GameplayStatics.h"

AReporterSubsystem::AReporterSubsystem()
{
	UpdateInterval = 5.0f;
	NumPlayersInSession = 1;
	MaxPlayers = 4;
	PlayerPresence = "Session Loading...";
	DiscordTier = "Session Loading...";
	DiscordDetails = "Session Loading...";
	DiscordState = "Session Loading...";
	GameLanguage = "Session Loading...";
	DiscordApplicationID = "1082738646173614143";
	DiscordObject = nullptr;
	bAllowDebugLogging = ModConfig.bAllowDebugLogging;
	UpdateInterval = ModConfig.UpdateInterval;

	// Initialize variables from config, unless we are in the editor, as that would crash the engine
	{
	#if WITH_EDITOR
			UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Shipping env not detected, avoiding crash"));
	#else
		ModConfig = FDRP_ConfigStruct::GetActiveConfig(GetWorld());
	#endif
	}
}

// Initialize Subsystem
void AReporterSubsystem::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Loaded FG_DRP Reporter Subsystem."));

	FModInfo ModInfo;
	UModLoadingLibrary* ModLoadingLibrary = GetGameInstance()->GetSubsystem<UModLoadingLibrary>();
	ModLoadingLibrary->GetLoadedModInfo("FG_DiscordRP", ModInfo);

	// Log the name, version, and build date of the mod
	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"), *ModInfo.FriendlyName.Append(", " + ModInfo.Version.ToString()));
	UE_LOG(LogFG_DISCORDRP, Display, TEXT("Build Date: %s %s"), ANSI_TO_TCHAR(__DATE__), ANSI_TO_TCHAR(__TIME__));

	// Get the language for the interpreter to use later
	GameLanguage = UFGBlueprintFunctionLibrary::GetLanguage();
	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"), *GameLanguage.Append(" is the language being used."));

	// Create and assign our DiscordObject to a variable
	UDiscordObject::CreateDiscordObject(DiscordApplicationID, false, true);
	DiscordObject = UDiscordObject::GetDiscordObject();

	// Get the Player Controller and Player State
	const AFGPlayerController* PlayerController = Cast<AFGPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	const APlayerState* PlayerState = PlayerController->GetPlayerState<APlayerState>();

	// UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"), *PlayerState->GetPlayerName().Append(" has joined the game."));

	if (AFGAdminInterface* AdminInterface = PlayerController->GetAdminInterface())
	{
		//UCLASS(notplaceable)
		//class FACTORYGAME_API AFGAdminInterface : public AInfo
		//{
		//	GENERATED_BODY()
		//
		//	friend class AReporterSubsystem;

		// IF THIS ERRORS IN NEWER VERSIONS, ADD 'friend class AReporterSubsystem;' TO THE AREA ABOVE ON FGAdminInterface.h

		// Get the amount of players allowed in the game session
		//MaxPlayers = AdminInterface->GetGameSession()->MaxPlayers;

		// Set our session visibility which affects whether we can retrieve the data we want
		// AdminInterface->SetSessionVisibility(ESessionVisibility::SV_FriendsOnly);
	}

	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AReporterSubsystem::ProcessPresenceString, 5.0f,true, 5.0f);
}

// End the subsystem when leaving the world to prevent crashing
void AReporterSubsystem::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EEndPlayReason::LevelTransition);

	GetWorldTimerManager().ClearTimer(MemberTimerHandle);
}

// Get and process the local player presence string
void AReporterSubsystem::ProcessPresenceString()
{
	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Beginning processing..."));

	// Thanks to SirDigby for helping me with this

	//UCLASS(BlueprintType)
	//class FACTORYGAME_API UFGLocalPlayer : public ULocalPlayer
	//{
	//	GENERATED_BODY()
	//
	//	friend class AReporterSubsystem;

	// IF THIS CREATES ERRORS IN NEWER VERSIONS, ADD 'friend class AReporterSubsystem;' TO THE AREA ABOVE ON FGLocalPlayer.h
	FPlayerPresenceState PlayerPresenceState;
	Cast<UFGLocalPlayer>(this->GetWorld()->GetGameInstance()->GetFirstLocalPlayerController()->GetLocalPlayer())->GetPresenceState(PlayerPresenceState);
	PlayerPresence = PlayerPresenceState.mPresenceString;

	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Current presence string: %s"), *PlayerPresence);

	FString OutTier;
	FString OutDetails;
	FString OutState;
	bool bTutorialException = false;

	PlayerPresence.Split(TEXT(":"), &DiscordTier, &OutTier);
	OutTier.Split(TEXT("in"), &DiscordDetails, &OutDetails, ESearchCase::IgnoreCase, ESearchDir::FromEnd);
	OutDetails.Split(TEXT("."), &DiscordState, &OutState, ESearchCase::IgnoreCase, ESearchDir::FromEnd);

	// If we are a client, skip this step
	// if (this->GetWorld()->GetNetMode() != NM_Client)
	// {
	// 	  // Get Player Count
	// 	  NumPlayersInSession = UGameplayStatics::GetGameMode(GetWorld())->GetNumPlayers();
	// }

	// DiscordObject->SetPartySize(NumPlayersInSession);
	// DiscordObject->SetPartyMax(MaxPlayers);

	// Add a catch for if the player is currently in the tutorial phase
	if (bTutorialException)
	{
		PlayerPresence.Split(TEXT("."), &DiscordDetails, &DiscordState);
	}
	else
	{
		DiscordObject->SetState(DiscordState);
		DiscordObject->SetDetails(DiscordDetails);
	}

	UDiscordThumbnails::UpdateThumbnails(DiscordState, DiscordTier, PlayerPresence, DiscordObject, bTutorialException);
}