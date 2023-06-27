// Created by ryanjon2040, modified for Satisfactory by SpaceGameDev568

#include "FG_DiscordRP.h"
#include "Interfaces/IPluginManager.h"
#include "Runtime/Core/Public/Misc/MessageDialog.h"

#define LOCTEXT_NAMESPACE "FFG_DiscordRPModule"

void* FFG_DiscordRPModule::DiscordHandle = nullptr;

void FFG_DiscordRPModule::StartupModule()
{

	// Get the base directory of this plugin
	const FString BaseDir = IPluginManager::Get().FindPlugin("FG_DiscordRP")->GetBaseDir();

	// Add on the relative location of the third party dll and load it

#if PLATFORM_WINDOWS
	const FString DiscordDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("DiscordSDK"), TEXT("Win64"));
#elif PLATFORM_MAC
	const FString DiscordDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("DiscordSDK"), TEXT("Mac"));
#elif PLATFORM_LINUX
	const FString DiscordDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("DiscordSDK"), TEXT("Linux"), TEXT("x86_64-unknown-linux-gnu"));
#endif

#if PLATFORM_LINUX
	static const FString DiscordLibName = "libdiscord_game_sdk";
#else
	static const FString DiscordLibName = "discord_game_sdk";
#endif

	const bool bDependencyLoaded = Internal_LoadDependency(DiscordDir, DiscordLibName, DiscordHandle);
	if (!bDependencyLoaded)
	{
		FFormatNamedArguments Arguments;
		Arguments.Add(TEXT("Name"), FText::FromString(DiscordLibName));
		Arguments.Add(TEXT("Path"), FText::FromString(DiscordDir));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name} from path {Path}."), Arguments));
		Internal_FreeDependency(DiscordHandle);
	}
}

void FFG_DiscordRPModule::ShutdownModule()
{
	Internal_FreeDependency(DiscordHandle);
}

bool FFG_DiscordRPModule::Internal_LoadDependency(const FString& Dir, const FString& Name, void*& Handle)
{
#if PLATFORM_WINDOWS || PLATFORM_MAC || PLATFORM_LINUX
	FString Lib = Name + TEXT(".") + FPlatformProcess::GetModuleExtension();
	FString Path = Dir.IsEmpty() ? *Lib : FPaths::Combine(*Dir, *Lib);

	Handle = FPlatformProcess::GetDllHandle(*Path);

	if (Handle == nullptr)
	{
		return false;
	}
	
	return true;
#else
	return false;
#endif
}

void FFG_DiscordRPModule::Internal_FreeDependency(void*& Handle)
{
#if PLATFORM_WINDOWS || PLATFORM_MAC || PLATFORM_LINUX
	if (Handle != nullptr)
	{
		FPlatformProcess::FreeDllHandle(Handle);
		Handle = nullptr;
	}
#endif
}

#undef LOG_NORMAL
#undef LOG_ERROR
#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFG_DiscordRPModule, FG_DiscordRP)