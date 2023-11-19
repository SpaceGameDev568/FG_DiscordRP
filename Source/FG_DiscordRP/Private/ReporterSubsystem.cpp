// Copyright 2023 Jesse Hodgson. All Rights Reserved.

// A message to any other modders looking at my horrendous code,
// please understand that I have no idea how cpp works and this is just an attempt to fix my mod

#include "ReporterSubsystem.h"

#include <chrono>

#include "FG_DiscordRP.h"
#include "FGBlueprintFunctionLibrary.h"
#include "FGNetworkLibrary.h"
#include "FGPlayerController.h"
#include "FGLocalPlayer.h"
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
	}
	// End Subsystem Initialization
}
void AReporterSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Shut down subsystem if the user disabled it in the config
	if(SubsystemDisabled)
	{
		SetActorTickEnabled(false);
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Subsystem disabled in config, shutting down..."));
		UDiscordObject::DestroyDiscordObject();
	}
	else
	{
		// Wait for the specified update interval
		// https://forums.unrealengine.com/t/delay-function-equivalent-in-c/339952
		FTimerHandle TimerHandle;
		// Note: Currently doesn't pause the subsystem and spams the shit out of the log
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AReporterSubsystem::ProcessPresenceString, 5, false);
	}
}
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
	auto pString = pState.mPresenceString;

	ULangEnglish::InterpretEnglish(pString, pString, pString, DiscordObject);

	// FString::Split(":", TierString, DetailsString, ESearchCase::IgnoreCase, ESearchDir::FromStart);

	// TierString = StateString;
}
// Update Discord presence
void AReporterSubsystem::UpdatePresenceState()
{
	DiscordObject->SetState(StateString);
	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"), *StateString);
	DiscordObject->SetState(DetailsString);
	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"), *DetailsString);
	DiscordObject->SetPartySize(NumPlayersInSession);
	DiscordObject->SetPartyMax(4);
}
