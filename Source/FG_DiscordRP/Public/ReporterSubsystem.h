// Copyright 2023 Jesse Hodgson. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DiscordObject.h"
#include "FGPlayerController.h"
#include "Subsystem/ModSubsystem.h"
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

	virtual void Tick(float DeltaTime) override;

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

	UFUNCTION()
	void ProcessPresenceString();

	// UFUNCTION()
	// void UpdatePresenceState();

};