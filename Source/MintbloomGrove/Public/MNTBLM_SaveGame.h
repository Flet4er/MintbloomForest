// Copyright (c) Shining Games 2026

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GameplayTagContainer.h"
#include "MNTBLM_SaveGame.generated.h"

/**
 * 
 */
UCLASS()
class MINTBLOOMGROVE_API UMNTBLM_SaveGame : public USaveGame
{
	GENERATED_BODY()
public:
	UMNTBLM_SaveGame();

	UPROPERTY(BlueprintReadWrite)
	FVector PawnLocation;
	UPROPERTY(BlueprintReadWrite)
	TArray<FString> PawnInventory;
	UPROPERTY(BlueprintReadWrite)
	TArray<FString> ChestInventory;
	UPROPERTY(BlueprintReadWrite)
	TArray<FString> CoockingPotInventory;
	UPROPERTY(BlueprintReadWrite)
	TArray<FString> TeaPotInventory;
	UPROPERTY(BlueprintReadWrite)
	TMap<FGameplayTag, int> BuildingUpgrade;
	UPROPERTY(BlueprintReadWrite)
	TArray<FString> JournalCollected;
};
