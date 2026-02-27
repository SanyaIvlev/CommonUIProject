// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CommonUIProject : ModuleRules
{
	public CommonUIProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"DeveloperSettings",
			"GameplayTags"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"CommonUIProject",
			"CommonUIProject/Variant_Platforming",
			"CommonUIProject/Variant_Platforming/Animation",
			"CommonUIProject/Variant_Combat",
			"CommonUIProject/Variant_Combat/AI",
			"CommonUIProject/Variant_Combat/Animation",
			"CommonUIProject/Variant_Combat/Gameplay",
			"CommonUIProject/Variant_Combat/Interfaces",
			"CommonUIProject/Variant_Combat/UI",
			"CommonUIProject/Variant_SideScrolling",
			"CommonUIProject/Variant_SideScrolling/AI",
			"CommonUIProject/Variant_SideScrolling/Gameplay",
			"CommonUIProject/Variant_SideScrolling/Interfaces",
			"CommonUIProject/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
