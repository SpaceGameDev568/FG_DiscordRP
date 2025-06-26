// Copyright 2023 - 2025 Jesse Hodgson. All Rights Reserved.

using UnrealBuildTool;

public class FG_DiscordRP : ModuleRules
{
	public FG_DiscordRP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		CppStandard = CppStandardVersion.Cpp20;

		// PublicIncludePaths.AddRange(
		// 	new[]
		// 	{
		// 		// ... add public include paths required here ...
		// 	}
		// );

		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"Core",
				"FactoryGame",
				"UMG",
				"DiscordPartnerSDK",
				"DiscordPartnerSDKLibrary",
				"SML"
				// ... add other public dependencies that you statically link with here ...
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore"
				// ... add private dependencies that you statically link with here ...	
			}
		);
	}
}