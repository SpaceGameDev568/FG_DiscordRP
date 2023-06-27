// Created by ryanjon2040, modified for Satisfactory by SpaceGameDev568

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogFG_DiscordRP, Verbose, All);

class FFG_DiscordRPModule : public IModuleInterface
{

private:
	
	static void* DiscordHandle;
	
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
		
	static bool Internal_LoadDependency(const FString& Dir, const FString& Name, void*& Handle);
	static void Internal_FreeDependency(void*& Handle);
};
