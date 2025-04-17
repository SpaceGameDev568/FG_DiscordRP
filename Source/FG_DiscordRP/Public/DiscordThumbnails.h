// Copyright 2023 - 2024 Jesse Hodgson. All Rights Reserved.

// #pragma once
//
// #include "CoreMinimal.h"
// #include "DiscordLocalPlayerSubsystem.h"
// #include "Kismet/BlueprintFunctionLibrary.h"
// #include "DiscordThumbnails.generated.h"
//
//
// // Info about file type: https://docs.unrealengine.com/5.3/en-US/blueprint-function-libraries-in-unreal-engine/
//
// UCLASS()
// class FG_DISCORDRP_API UDiscordThumbnails : public UBlueprintFunctionLibrary
// {
// 	GENERATED_BODY()
//
// public:
//
// 	UDiscordActivityAssets* Assets;
//
// 	UFUNCTION(BlueprintCallable, Category = "Discord")
// 	static void UpdateThumbnails(FString InStateString, FString InTierString, FString InPresenceString, UDiscordLocalPlayerSubsystem* Discord, UDiscordActivity* Activity, bool& bTutorialException);
// };