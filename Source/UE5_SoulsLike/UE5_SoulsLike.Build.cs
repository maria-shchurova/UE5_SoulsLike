// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE5_SoulsLike : ModuleRules
{
	public UE5_SoulsLike(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {"GameplayAbilities", "GameplayTags", "GameplayTasks", "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
