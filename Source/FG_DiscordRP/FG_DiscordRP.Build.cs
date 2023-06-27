// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class FG_DiscordRP : ModuleRules
{
	public FG_DiscordRP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
		);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
		);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"SML",
				"Engine",
				"InputCore",
				"OnlineSubsystem", "OnlineSubsystemUtils", "OnlineSubsystemNULL",
				"SignificanceManager",
				"PhysX", "APEX", "PhysXVehicles", "ApexDestruction",
				"AkAudio",
				"ReplicationGraph",
				"UMG",
				"AIModule",
				"NavigationSystem",
				"AssetRegistry",
				"GameplayTasks",
				"AnimGraphRuntime",
				"Slate", "SlateCore",
				"Json",
				"AbstractInstance"
				// ... add other public dependencies that you statically link with here ...
			}
		);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
		);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
		);
				if (Directory.Exists(DiscordPath) == false)
		{
			throw new BuildException("discord files not found. Check it exists here: " + DiscordPath);
		}

		if (File.Exists(DiscordLibFile) == false)
		{
			throw new BuildException(DiscordLibFileName + " was not found. Check it exists here: " + DiscordLibFile);
		}

		if (IsWin64() && File.Exists(DiscordRuntimeDepFile) == false)
		{
			throw new BuildException("discord_game_sdk.dll was not found. Check it exists here: " + DiscordRuntimeDepFile);
		}

		PublicIncludePaths.Add(DiscordPath);
		
		PublicDependencyModuleNames.AddRange( new string[] { "Core", "Projects" } );		
		PrivateDependencyModuleNames.AddRange( new string[] { "CoreUObject", "Engine" } );

		PublicAdditionalLibraries.Add(DiscordLibFile);
		if (IsWin64())
		{
			PublicDelayLoadDLLs.Add("discord_game_sdk.dll");
		}

		RuntimeDependencies.Add(DiscordRuntimeDepFile);
	}

	private string DiscordPath
	{
		get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "DiscordSDK")); }
	}

	private string DiscordLibFile
	{
		get
		{
			return Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/DiscordSDK/", GetPlatformName, DiscordLibFileName));
		}
	}

	private string DiscordLibFileName
	{
		get
		{
			if (IsWin64())
			{
				return "discord_game_sdk.dll.lib";
			}
			else if (IsMac())
			{
				return "discord_game_sdk.dylib";
			}
			else if (IsLinux())
			{
				return "libdiscord_game_sdk.so";
			}

			return null;
		}
	}

	private string DiscordRuntimeDepFile
	{
		get
		{
			// Only Windows needs separate library and runtime dependency files
			if (IsWin64())
			{
				return Path.GetFullPath(Path.Combine(ModuleDirectory, "../ThirdParty/DiscordSDK/Win64/discord_game_sdk.dll"));
			}
			else
			{
				return DiscordLibFile;
			}
		}
	}

	private bool IsWin64()
	{
		return Target.Platform == UnrealTargetPlatform.Win64;
	}

	private bool IsMac()
	{
		return Target.Platform == UnrealTargetPlatform.Mac;
	}

	private bool IsLinux()
	{
		return Target.Platform == UnrealTargetPlatform.Linux;
	}

	private string GetPlatformName
	{
		get 
		{
			if (IsWin64())
			{
				return "Win64";
			}
			else if (IsMac())
			{
				return "Mac";
			}
			else if (IsLinux())
			{
				return "Linux/x86_64-unknown-linux-gnu";
			}

			return null;
		}
	}
}