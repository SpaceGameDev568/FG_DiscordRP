// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

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
	}
}