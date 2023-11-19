// Copyright Epic Games, Inc. All Rights Reserved.

#include "FG_DiscordRP.h"

#define LOCTEXT_NAMESPACE "FFG_DiscordRPModule"

void FFG_DiscordRPModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FFG_DiscordRPModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

DEFINE_LOG_CATEGORY(LogFG_DISCORDRP);

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFG_DiscordRPModule, FG_DiscordRP)