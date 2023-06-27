#pragma once

#include "DiscordSubsystem.h"
#include "FG_DiscordRP.h"
#include "Subsystem/ModSubsystem.h"
#include "DiscordRPCServer.h"
#include "Online.h"
//#include "Internationalization/Internationalization.h"
#include "UObject/Object.h"

ADiscordSubsystem::ADiscordSubsystem()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickGroup = TG_PrePhysics;
}

void ADiscordSubsystem::BeginPlay()
{
	Super::BeginPlay();

	float UpdateInterval = 5.0f;
	bool SubsystemDisabled = false;
	//static int32 NumPlayersInSession = 0;
	//int BiomeCounter = 0;
	//FString TierString = "Session Loading...";
	//FString DetailsString = "Session Loading...";
	//FString StateString = "Session Loading...";
	//FString GameLanguage = "en-US-POSIX";
	FString DiscordClientID = "1082738646173614143";

	SetActorTickEnabled(true);

	UE_LOG(LogFG_DiscordRP, Verbose, TEXT("Loaded FG_DRP Reporter Subsystem."));

	//GameLanguage = FInternationalization::Get().GetCurrentLanguage()->GetName();

	UDiscordRPCServer::CreateDiscordRPCServer("1082738646173614143", false, true);

	DiscordRPCRef = UDiscordRPCServer::GetDiscordRPCServer();

	IsDiscordObjValid = IsValid(DiscordRPCRef);

	if (!IsDiscordObjValid) // Check if the newly created Discord Object is valid before continuing
	{
		UE_LOG(LogFG_DiscordRP, Error, TEXT("Discord Object not valid, exiting..."));
	}
	else // If the Discord Object is valid, continue running the code
	{
		UE_LOG(LogFG_DiscordRP, Verbose, TEXT("Discord Object is valid."));
	}
}

void ADiscordSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	UE_LOG(LogFG_DiscordRP, Verbose, TEXT("Subsystem is ticking."));

	if (SubsystemDisabled)
	{
		UE_LOG(LogFG_DiscordRP, Verbose, TEXT("Subsystem disabled. Shutting Down..."));

		SetActorTickEnabled(false);

		UDiscordRPCServer::DestroyDiscordRPCServer();
	}
	else
	{
		UE_LOG(LogFG_DiscordRP, Verbose, TEXT("Subsystem enabled. Continuing"));

		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, 5, false);

		//WorldRef = GetWorld();
		//
		//NumPlayersInSession = GEngine->GetNumGamePlayers(WorldRef);

		Online::GetPresenceInterface();
	}
}

void ADiscordSubsystem::DynamicDiscordUpdate()
{
	UDiscordRPCServer::SetState("Test");

	//UDiscordRPCServer::SetDetails(*DetailsString);

	UDiscordRPCServer::SetLargeImage("satisfactory_logo");

	//UDiscordRPCServer::SetPartySize(*NumPlayersInSession);

	//Can be moved out of ticking section later, only needs to be called once
	UDiscordRPCServer::SetPartyMax(4);
}
