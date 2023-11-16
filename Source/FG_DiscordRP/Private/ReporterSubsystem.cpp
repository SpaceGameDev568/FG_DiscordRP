// Copyright 2023 Jesse Hodgson. All Rights Reserved.


// #include "ReporterSubsystem.h"
// #include "FG_DiscordRP.h"
// #include "FGBlueprintFunctionLibrary.h"
// #include "FGNetworkLibrary.h"
// #include "FGPlayerController.h"
// #include "FGPlayerState.h"

// AReporterSubsystem::AReporterSubsystem()
// {
// 	PrimaryActorTick.bCanEverTick = true;
//
// 	UpdateInterval = 5.0f;
// 	SubsystemDisabled = false;
// 	NumPlayersInSession = 1;
// 	PresenceString = "Session Loading...";
// 	TierString = "Session Loading...";
// 	DetailsString = "Session Loading...";
// 	StateString = "Session Loading...";
// 	GameLanguage = "Session Loading...";
// 	DiscordClientID = "1082738646173614143";
// }
//
// // Initialize Subsystem
// void AReporterSubsystem::BeginPlay()
// {
// 	Super::BeginPlay();
//
// 	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Loaded FG_DRP Reporter Subsystem."));
//
// 	// Flush config before reading from it
// 	GConfig->Flush(true, GGameIni);
//
// 	// Get the language for the interpreter to use later
// 	GameLanguage = UFGBlueprintFunctionLibrary::GetLanguage();
//
// 	// Create and assign our DiscordObject to a variable
// 	UDiscordObject::CreateDiscordObject(DiscordClientID, false, true);
// 	DiscordObject = UDiscordObject::GetDiscordObject();
//
// 	// Log the value of our DiscordObject
// 	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"), *DiscordObject->GetName());
//
// 	// Check if our DiscordObject is valid or not before continuing
// 	if(IsValid(DiscordObject))
// 	{
// 		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Discord Object is valid."));
// 	}
// 	else
// 	{
// 		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Discord Object not valid, exiting..."));
// 	}
//
// 	// End Subsystem Initialization
// }
//
// void AReporterSubsystem::Tick(float DeltaTime)
// {
// 	Super::Tick(DeltaTime);
//
// 	// Shut down subsystem if the user disabled it in the config
// 	if(SubsystemDisabled)
// 	{
// 		SetActorTickEnabled(false);
//
// 		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Subsystem disabled in config, shutting down..."));
//
// 		UDiscordObject::DestroyDiscordObject();
// 	}
// 	else
// 	{
// 		// Wait for the specified update interval
// 		FTimerHandle TimerHandle;
// 		GetWorld()->GetTimerManager().SetTimer(TimerHandle, UpdateInterval, false);
//
// 		ProcessPresenceString();
// 	}
//
// }
//
// // Get and process the local player presence string
// void AReporterSubsystem::ProcessPresenceString()
// {
// 	// https://forums.unrealengine.com/t/solved-getworld-from-static-function-without-pass-an-object/245939/3
// 	// Get player controller reference
// 	playerController = UGameplayStatics::GetPlayerController(GEngine->GameViewport->GetWorld(), 0);
//
// 	//PlayerNetID = playerController->GetPlayerState->GetUniqueNetId();
//
// 	// Get player presence string
// 	PresenceString = UFGPresenceLibrary::GetPresenceString(UFGPresenceLibrary::GetPresenceFromNetId(GEngine->GameViewport->GetWorld(), PlayerNetID));
//
//
// }
//
// // Update Discord presence
// void AReporterSubsystem::UpdatePresenceState()
// {
// 	DiscordObject->SetState(StateString);
// 	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"), *StateString);
//
// 	DiscordObject->SetState(DetailsString);
// 	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"), *DetailsString);
//
// 	DiscordObject->SetPartySize(NumPlayersInSession);
// 	DiscordObject->SetPartyMax(4);
//
// }
//