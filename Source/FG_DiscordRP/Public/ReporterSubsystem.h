// Copyright 2023 - 2024 Jesse Hodgson. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DiscordObject.h"
#include "FGPlayerController.h"
#include "Subsystem/ModSubsystem.h"
#include "DRP_ConfigStruct.h"
#include "ReporterSubsystem.generated.h"

UCLASS()
class FG_DISCORDRP_API AReporterSubsystem : public AModSubsystem
{
	GENERATED_BODY()

public:

	AReporterSubsystem();

protected:

	virtual void BeginPlay() override;

public:

	UDiscordObject* DiscordObject;
	float UpdateInterval;
	bool SubsystemDisabled;
	int NumPlayersInSession;
	FString PresenceString;
	FString TierString;
	FString DetailsString;
	FString StateString;
	FString GameLanguage;
	FString DiscordClientID;
	FPlayerPresenceState PresenceState;

	FDRP_ConfigStruct myConfig;

	bool EnableDebugLogging;
	bool DisableSubsystem;
	bool IsDeveloper;
	//bool ResetDiscordObject;

	UFUNCTION()
	void ProcessPresenceString();

};