// Copyright 2023 - 2024 Jesse Hodgson. All Rights Reserved.

#include "ReporterSubsystem.h"
#include "FG_DiscordRP.h"
#include "FGBlueprintFunctionLibrary.h"
#include "FGNetworkLibrary.h"
#include "FGPlayerController.h"
#include "FGLocalPlayer.h"
#include "FGPlayerControllerBase.h"
#include "FGAdminInterface.h"
#include "LangEnglish.h"
#include "GameFramework/GameMode.h"
#include "DRP_ConfigStruct.h"
#include "Net/UnrealNetwork.h"

AReporterSubsystem::AReporterSubsystem()
{
	bReplicates = true;

	UpdateInterval = 5.0f;
	NumPlayersInSession = 1;
	PresenceString = "Session Loading...";
	TierString = "Session Loading...";
	DetailsString = "Session Loading...";
	StateString = "Session Loading...";
	GameLanguage = "Session Loading...";
	DiscordClientID = "1082738646173614143";
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
	//ResetDiscordObject = myConfig.reset_discord_object;

}

// Initialize Subsystem
void AReporterSubsystem::BeginPlay()
{
	Super::BeginPlay();

	if(EnableDebugLogging)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Loaded FG_DRP Reporter Subsystem."));
	}
	// Get the language for the interpreter to use later
	GameLanguage = UFGBlueprintFunctionLibrary::GetLanguage();
	// Create and assign our DiscordObject to a variable
	UDiscordObject::CreateDiscordObject(DiscordClientID, false, true);
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

	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"), *PCRef->GetName());

	if (PCRef != nullptr)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("PCRef is a null pointer"));
	}

	AFGPlayerController* VarPlayerController = Cast<AFGPlayerController>(PCRef);

	ESessionVisibility SessionVisibility = ESessionVisibility::SV_FriendsOnly;

	// Potential null pointer ^v REMEMBER TO FIX
	if (VarPlayerController != nullptr)
	{
		VarPlayerController->GetAdminInterface()->SetSessionVisibility(SessionVisibility);
	}
	else
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("VarPlayerController is a null pointer"));
	}


	FTimerHandle MemberTimerHandle;

	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AReporterSubsystem::ProcessPresenceString, UpdateInterval, true, UpdateInterval);
	// End Subsystem Initialization
}

// Get and process the local player presence string
void AReporterSubsystem::ProcessPresenceString()
{

// // Manually reset the Discord Object if the user thinks there's a problem
// ResetDiscordObject = myConfig.reset_discord_object;

// if(ResetDiscordObject)
// {
// 	if(EnableDebugLogging)
// 	{
// 		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Discord Object reset requested"));
// 	}

// 	myConfig.reset_discord_object = false;
// 	GConfig->Flush(true, GGameIni);
// 	DiscordObject->DestroyDiscordObject();

// 	// Create and assign our DiscordObject to a variable
// 	UDiscordObject::CreateDiscordObject(DiscordClientID, false, true);
// 	DiscordObject = UDiscordObject::GetDiscordObject();
// 	// Log the value of our DiscordObject
// 	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"), *DiscordObject->GetName());
// 	// Check if our DiscordObject is valid or not before continuing
// 	if(IsValid(DiscordObject))
// 	{
// 		if(EnableDebugLogging)
// 		{
// 			UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Discord Object is valid."));
// 		}
// 	}
// 	else
// 	{
// 		if(EnableDebugLogging)
// 		{
// 			UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Discord Object not valid, exiting..."));
// 		}
// 		this->Destroy();
// 	}
// }

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

	if(EnableDebugLogging)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"),*pString);
	}

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

	DiscordObject->SetPartyMax(4);

}