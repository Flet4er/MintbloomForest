// Copyright (c) Shining Games 2026

using UnrealBuildTool;
using System.Collections.Generic;

public class MintbloomGroveEditorTarget : TargetRules
{
	public MintbloomGroveEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V6;

		ExtraModuleNames.AddRange( new string[] { "MintbloomGrove" } );
	}
}
