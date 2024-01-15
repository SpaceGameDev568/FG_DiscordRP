// Copyright 2023 Jesse Hodgson. All Rights Reserved.

#include "ReporterSubsystem.h"

#include <chrono>

#include "FG_DiscordRP.h"
#include "FGBlueprintFunctionLibrary.h"
#include "FGNetworkLibrary.h"
#include "FGPlayerController.h"
#include "FGLocalPlayer.h"
#include "FGPlayerControllerBase.h"
#include "FGAdminInterface.h"
#include "LangEnglish.h"

AReporterSubsystem::AReporterSubsystem()
{
	PrimaryActorTick.bCanEverTick = true;
	UpdateInterval = 5.0;
	SubsystemDisabled = false;
	NumPlayersInSession = 1;
	PresenceString = "Session Loading...";
	TierString = "Session Loading...";
	DetailsString = "Session Loading...";
	StateString = "Session Loading...";
	GameLanguage = "Session Loading...";
	DiscordClientID = "1082738646173614143";

}
// Initialize Subsystem
void AReporterSubsystem::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Loaded FG_DRP Reporter Subsystem."));
	// Flush config before reading from it
	GConfig->Flush(true, GGameIni);
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
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Discord Object not valid, exiting..."));
		this->Destroy();
	}

	APlayerController* pcRef;

	// Set the session type to friends only
	pcRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	auto varPlayerController = Cast<AFGPlayerController>(pcRef->GetLocalPlayer());

	varPlayerController->GetAdminInterface()->SetSessionVisibility(ESessionVisibility::SV_FriendsOnly);

	FTimerHandle MemberTimerHandle;

	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AReporterSubsystem::ProcessPresenceString, 5.0f, true, 5.0f);
	// End Subsystem Initialization
}

//void AReporterSubsystem::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//	// Shut down subsystem if the user disabled it in the config
//	if(SubsystemDisabled)
//	{
//		SetActorTickEnabled(false);
//		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Subsystem disabled in config, shutting down..."));
//		UDiscordObject::DestroyDiscordObject();
//	}
//	else
//	{
//		// Wait for the specified update interval
//		// https://forums.unrealengine.com/t/delay-function-equivalent-in-c/339952
//
//		// Note: Currently doesn't pause the subsystem and spams the shit out of the log
//		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AReporterSubsystem::ProcessPresenceString, 5, false);
//	}
//}

// Get and process the local player presence string
void AReporterSubsystem::ProcessPresenceString()
{

	// Credit to SirDigby for helping me with this
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

	TierSplitOut.Split(TEXT("in"), &DetailsString, &DetailsSplitOut);

	FString StateSplitOutDISCARD;

	DetailsSplitOut.Split(TEXT("."), &StateString, &StateSplitOutDISCARD);

	ULangEnglish::InterpretEnglish(StateString, TierString, pString, DiscordObject);

	DiscordObject->SetState(StateString);

	DiscordObject->SetDetails(DetailsString);

	DiscordObject->SetPartySize(NumPlayersInSession);

	DiscordObject->SetPartyMax(4);
}
// Update Discord presence
// void AReporterSubsystem::UpdatePresenceState()
// {
// 	DiscordObject->SetState(StateString);
// 	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"), *StateString);
// 	DiscordObject->SetDetails(DetailsString);
// 	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"), *DetailsString);
// 	DiscordObject->SetPartySize(NumPlayersInSession);
// 	DiscordObject->SetPartyMax(4);
// }
