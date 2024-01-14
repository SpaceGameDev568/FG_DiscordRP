

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FFG_DiscordRPModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

DECLARE_LOG_CATEGORY_EXTERN(LogFG_DISCORDRP, Verbose, All);