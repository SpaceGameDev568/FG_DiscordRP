#pragma once

#include "DiscordSubsystem.h"
#include "FG_DiscordRP.h"
#include "Actor.h"
#include "Subsystem/ModSubsystem.h"
#include "DiscordUE4/Public/DiscordObject.h"
#include "Internationalization/Internationalization.h"
#include "UObject/Object.h"

void ADiscordSubsystem::BeginPlay()
{
	Super::BeginPlay();
	
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

		// To-do: Log DiscordObject display name
	}
}

void ADiscordSubsystem::Tick()
{
	Super::Tick(0);

	if (SubsystemDisabled)
	{
		UE_LOG(LogFG_DiscordRP, Verbose, TEXT("Subsystem disabled. Shitting Down..."));
	}
}