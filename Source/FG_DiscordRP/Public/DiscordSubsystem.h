#pragma once

#include "CoreMinimal.h"
#include "Subsystem/ModSubsystem.h"
#include "DiscordObject.h"
#include "DiscordSubsystem.generated.h"

UCLASS()
class FG_DISCORDRP_API ADiscordSubsystem : public AModSubsystem
{
	GENERATED_BODY()

private:

	static UWorld* WorldRef;
	float UpdateInterval;
	bool SubsystemDisabled;
	static int32 NumPlayersInSession;
	int BiomeCounter;
	static UDiscordObject* DiscordObjectRef;
	FString TierString;
	FString DetailsString;
	FString StateString;
	FString GameLanguage;
	FString DiscordClientID;
	bool IsDiscordObjValid;
	
public:
	
ADiscordSubsystem();

protected:
	
	virtual void BeginPlay() override;
	
public:
	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	static void DynamicDiscordUpdate();
};
