// Copyright 2023 Jesse Hodgson. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DiscordObject.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LangEnglish.generated.h"


// Info about file type: https://docs.unrealengine.com/5.3/en-US/blueprint-function-libraries-in-unreal-engine/

UCLASS()
class FG_DISCORDRP_API ULangEnglish : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Discord")
	static void InterpretEnglish(FString InStateString, FString InTierString, FString InPresenceString, UDiscordObject* DiscordObject);
};
