#pragma once

#include "CoreMinimal.h"
#include "Subsystem/ModSubsystem.h"
#include "DiscordUE4/Public/DiscordObject.h"
#include "DiscordSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class FG_DISCORDRP_API ADiscordSubsystem : public AModSubsystem
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
	virtual void Tick();

	float UpdateInterval = 5.0f;
	bool SubsystemDisabled = false;
	int NumPlayersInSession = 0;
	int BiomeCounter = 0;
	UDiscordObject* DiscordObjectRef;
	FString TierString = "Session Loading...";
	FString DetailsString = "Session Loading...";
	FString StateString = "Session Loading...";
	FString GameLanguage = "en-US-POSIX";
	FString DiscordClientID = "1082738646173614143";

	bool IsDiscordObjValid;
};
