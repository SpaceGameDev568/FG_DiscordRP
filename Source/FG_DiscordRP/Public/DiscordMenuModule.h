// Copyright 2024 Jesse Hodgson.

#pragma once

#include "CoreMinimal.h"
#include "Module/MenuWorldModule.h"
#include "Blueprint/UserWidget.h"
#include "DiscordMenuModule.generated.h"
UCLASS()
class FG_DISCORDRP_API UDiscordMenuModule : public UMenuWorldModule
{
	GENERATED_BODY()

public:

	UDiscordMenuModule();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UUserWidget> MenuWidgetClass; // The notification widget class to show on the main menu

	UFUNCTION(BlueprintCallable, Category = "Discord Integration")
	void Init(); // Initialize the module in subclasses
};