// Copyright 2023 Jesse Hodgson. All Rights Reserved.


#include "ReporterFuncLib.h"
#include "FG_DiscordRP.h"
#include "DiscordObject.h"
#include "FGBlueprintFunctionLibrary.h"

void UReporterFuncLib::InitializeReporter(FString &DiscordClientID, FString &GameLanguage, UDiscordObject* &DiscordObject)
{
	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Loaded FG_DRP Reporter Subsystem."));

	// Flush config before reading from it
	GConfig->Flush(true, GGameIni);

	// Get the language for the interpreter to use later
	GameLanguage = UFGBlueprintFunctionLibrary::GetLanguage();

	// Create and assign our DiscordObject to a variable
	UDiscordObject::CreateDiscordObject(DiscordClientID, false, true);
	DiscordObject = UDiscordObject::GetDiscordObject();

	// Log the value of our DiscordObject
	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"), *DiscordObject->GetName());

	// Check if our DiscordObject is valid or not before continuing
	if(IsValid(DiscordObject))
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Discord Object is valid."));
	}
	else
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Discord Object not valid, exiting..."));
	}
}
