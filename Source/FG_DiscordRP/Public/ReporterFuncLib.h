// Copyright 2023 Jesse Hodgson. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DiscordObject.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ReporterFuncLib.generated.h"

/**
 * 
 */
UCLASS()
class FG_DISCORDRP_API UReporterFuncLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Discord")
	static void InitializeReporter(FString &DiscordClientID, FString &GameLanguage, UDiscordObject* &DiscordObject);
};
