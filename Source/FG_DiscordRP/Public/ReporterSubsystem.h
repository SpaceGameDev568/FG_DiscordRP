// Copyright 2023 - 2025 Jesse Hodgson

#pragma once

#include "CoreMinimal.h"
#include "DiscordActions.h"
#include "DiscordUnreal.h"
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

	UPROPERTY()
	UDiscordActivity* Activity;

	UPROPERTY()
	UDiscordActivityAssets* Assets;

	UPROPERTY()
	UDiscordActivityParty* Party;

	// UPROPERTY()
	// UDiscordActivityButton* Button;

	UPROPERTY()
	UDiscordLocalPlayerSubsystem* Discord;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ActorClass;

	//UPROPERTY()
	//ADiscordActions* DiscordActions;

	FString LargeImage;
	FString LargeImageText;
	FString SmallImage;
	FString SmallImageText;

	FString PlayerPresence; // The player's presence in the game

	FString DiscordTier; // The player's tier in the game

	FString DiscordDetails; // Additional details about the user's game status

	FString DiscordState; // The player's current state in the game

	FString GameLanguage; // The player's preferred language

	FString DiscordApplicationID; // The Discord application ID: https://discord.com/developers/applications/1082738646173614143/information

	FPlayerPresenceState PresenceState; // The player's presence state in the game

	FDRP_ConfigStruct ModConfig; // Our global mod configuration structure

	FTimerHandle MemberTimerHandle; // The timer handle for updating our presence info

	float UpdateInterval; // Time interval between updates

	int NumPlayersInSession; // The number of players currently in the game session

	int MaxPlayers; // Maximum amount of players allowed in the session

	bool bAllowDebugLogging; // Whether the player wants to do additional logging for debugging purposes

	UFUNCTION()
	void ProcessPresenceString();

	void OnRichPresenceUpdated(UDiscordClientResult* Result);

	UFUNCTION()
	void UpdateThumbnails(bool& bTutorialException);

protected:

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	void OnLogMessage(FString Message, EDiscordLoggingSeverity Severity);
};