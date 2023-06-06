#pragma once

#include "DiscordSubsystem.h"
#include "FG_DiscordRP.h"
#include "Subsystem/ModSubsystem.h"
#include "DiscordObject.h"
#include "Internationalization/Internationalization.h"
#include "UObject/Object.h"

ADiscordSubsystem::ADiscordSubsystem()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickGroup = TG_PrePhysics;
}

void ADiscordSubsystem::BeginPlay()
{
	Super::BeginPlay();

	SetActorTickEnabled(true);

	UE_LOG(LogFG_DiscordRP, Verbose, TEXT("Loaded FG_DRP Reporter Subsystem."));

	GameLanguage = FInternationalization::Get().GetCurrentLanguage()->GetName();

	UDiscordObject::CreateDiscordObject("1082738646173614143", false, true);

	DiscordObjectRef = UDiscordObject::GetDiscordObject();

	IsDiscordObjValid = IsValid(DiscordObjectRef);

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

		UDiscordObject::DestroyDiscordObject();
	}
	else
	{
		UE_LOG(LogFG_DiscordRP, Verbose, TEXT("Subsystem disabled. Shutting Down..."));

		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, UpdateInterval, false);

		UDiscordObject::SetState("Test");
	}
}
