// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UtilityProject : ModuleRules
{
	public UtilityProject(ReadOnlyTargetRules Target) : base(Target)
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
			"GameplayTags"
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			
		});

		PublicIncludePaths.AddRange(new string[] {
			"UtilityProject",
			"UtilityProject/Variant_Platforming",
			"UtilityProject/Variant_Platforming/Animation",
			"UtilityProject/Variant_Combat",
			"UtilityProject/Variant_Combat/AI",
			"UtilityProject/Variant_Combat/Animation",
			"UtilityProject/Variant_Combat/Gameplay",
			"UtilityProject/Variant_Combat/Interfaces",
			"UtilityProject/Variant_Combat/UI",
			"UtilityProject/Variant_SideScrolling",
			"UtilityProject/Variant_SideScrolling/AI",
			"UtilityProject/Variant_SideScrolling/Gameplay",
			"UtilityProject/Variant_SideScrolling/Interfaces",
			"UtilityProject/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
