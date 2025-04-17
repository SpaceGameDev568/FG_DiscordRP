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
    float UpdateInterval{};

    UPROPERTY(BlueprintReadWrite)
    bool bAllowDebugLogging{};

    UPROPERTY(BlueprintReadWrite)
    FString DiscordAccessToken{};

    UPROPERTY(BlueprintReadWrite)
    FString DiscordRefreshToken{};

    UPROPERTY(BlueprintReadWrite)
    int32 DiscordRefreshTokenType{};

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

