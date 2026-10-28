// Copyright (c) Shining Games 2026

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayTagContainer.h"
#include "MintbloomFunctionalLibrary.generated.h"

/**
 * 
 */

UCLASS()
class MINTBLOOMGROVE_API UMintbloomFunctionalLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "World")
	static bool GetPlayInEditor();

	UFUNCTION(BlueprintPure, Category = "UI")
	static FIconRow GetIconRow(FString IconName);

	UFUNCTION(BLueprintCallable, Category = "World")
	static FGameplayTagContainer GetAllCollectableItem(FGameplayTag ParentTag);
};
