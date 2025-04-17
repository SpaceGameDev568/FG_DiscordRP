// Copyright 2024 Jesse Hodgson.

#include "DiscordMenuModule.h"
#include "FGBlueprintFunctionLibrary.h"
#include "FG_DiscordRP.h"
#include "WorldModuleManager.h"

UDiscordMenuModule::UDiscordMenuModule()
{
}

void UDiscordMenuModule::Init()
{

	// Add the popup in the Main Menu
	// const FPopupClosed CloseDelegate;
//
	// UFGBlueprintFunctionLibrary::AddPopupWithCloseDelegate(GetWorld()->GetFirstPlayerController(), FText::FromString("Discord Integration"), FText::FromString("Body Text"), CloseDelegate, PID_NONE, MenuWidgetClass, this, false);

}