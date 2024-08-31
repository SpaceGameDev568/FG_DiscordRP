// Copyright 2023 - 2024 Jesse Hodgson. All Rights Reserved.

using UnrealBuildTool;

public class FG_DiscordRP : ModuleRules
{
	public FG_DiscordRP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(
			new[]
			{
				"DiscordSDK"
				// ... add public include paths required here ...
			}
		);

		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"Core",
				"DiscordUE4",
				"FactoryGame",
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