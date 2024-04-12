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

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	// Pointer to a DiscordObject, used for interacting with the Discord API
	UDiscordObject* DiscordObject;

	// Time interval for updates
	float UpdateInterval;

	// Number of players currently in the game session
	int NumPlayersInSession;

	int MaxPlayers;

	// String representing the user's presence in the game
	FString PresenceString;

	// String representing the user's tier in the game
	FString TierString;

	// String representing additional details about the user's game status
	FString DetailsString;

	// String representing the user's current state in the game
	FString StateString;

	// String representing the language used in the game
	FString GameLanguage;

	// String representing the Discord application ID: https://discord.com/developers/applications/1082738646173614143/information
	FString DiscordApplicationID;

	// Enum representing the user's presence state in the game
	FPlayerPresenceState PresenceState;

	FDRP_ConfigStruct myConfig;

	bool EnableDebugLogging;
	bool IsDeveloper;

	FTimerHandle MemberTimerHandle;

	UFUNCTION()
	void ProcessPresenceString();
};
