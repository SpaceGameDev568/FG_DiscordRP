#pragma once
#include "CoreMinimal.h"
#include "Configuration/ConfigManager.h"
#include "Engine/Engine.h"
#include "DRP_ConfigStruct.generated.h"

/* Struct generated from Mod Configuration Asset '/FG_DiscordRP/DRP_Config' */
USTRUCT(BlueprintType)
struct FDRP_ConfigStruct {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    float update_interval{};

    UPROPERTY(BlueprintReadWrite)
    bool reset_discord_object{};

    UPROPERTY(BlueprintReadWrite)
    bool disable_subsystem{};

    UPROPERTY(BlueprintReadWrite)
    bool debug_logging{};

    UPROPERTY(BlueprintReadWrite)
    bool is_developer{};

    /* Retrieves active configuration value and returns object of this struct containing it */
    static FDRP_ConfigStruct GetActiveConfig(UObject* WorldContext) {
        FDRP_ConfigStruct ConfigStruct{};
        FConfigId ConfigId{"FG_DiscordRP", ""};
        if (const UWorld* World = GEngine->GetWorldFromContextObject(WorldContext, EGetWorldErrorMode::ReturnNull)) {
            UConfigManager* ConfigManager = World->GetGameInstance()->GetSubsystem<UConfigManager>();
            ConfigManager->FillConfigurationStruct(ConfigId, FDynamicStructInfo{FDRP_ConfigStruct::StaticStruct(), &ConfigStruct});
        }
        return ConfigStruct;
    }
};

