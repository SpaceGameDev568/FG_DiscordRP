

#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TestFunctionLibrary.generated.h"

// Info about file type: https://docs.unrealengine.com/5.3/en-US/blueprint-function-libraries-in-unreal-engine/

/**
 * 
 */
UCLASS()
class FG_DISCORDRP_API UTestFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "DiscordRP")
	static void InterpretLanguage(FString InStateString);
	
};
