// Copyright (c) Shining Games 2026

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"
#include "CraftingRecipes.generated.h"

USTRUCT(BlueprintType)
struct MINTBLOOMGROVE_API FCraftingRecipes : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
	FGameplayTag RecipeItemTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
	TMap<FGameplayTag, int> Ingredients;
};