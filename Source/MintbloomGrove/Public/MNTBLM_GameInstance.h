// Copyright (c) Shining Games 2026

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MNTBLM_SaveGame.h"
#include "MNTBLM_GameInstance.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FSavingStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector PawnLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> PawnInventory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> ChestInventory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> CoockingPotInventory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> TeaPotInventory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FGameplayTag, int> BuildingUpgrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> JournalCollected;
};
UCLASS()
class MINTBLOOMGROVE_API UMNTBLM_GameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UPROPERTY()
	TObjectPtr<UMNTBLM_SaveGame> SaveObject;
	FString SaveSlot = TEXT("SaveGame");
	FString CurrentSavePath = TEXT("Saved/SaveGames");

	UFUNCTION()
	virtual void Init() override;

	UFUNCTION(BlueprintCallable)
	UMNTBLM_SaveGame* GetSaveGameObject();

	UFUNCTION(BlueprintCallable)
	UMNTBLM_SaveGame* LoadGame(FString Slot);

	UFUNCTION(BlueprintCallable)
	void SaveGameSlot();
	
	/*saving Pawn Variables*/
	UFUNCTION(BlueprintCallable)
	void SaveCharacterLocation(FVector Location);

	UFUNCTION(BlueprintCallable)
	void SaveCharacterInventory(TArray<FString> Inventory);

	UFUNCTION(BlueprintCallable)
	void SaveCharacterStatus(); // TBD need to save buffs/debuffs current stamina,hunger etc

	/*saving Crafting Station Inventory*/
	UFUNCTION(BlueprintCallable)
	void SaveCookingPotInventory(TArray<FString> Inventory);
	UFUNCTION(BlueprintCallable)
	void SaveTeaPotInventory(TArray<FString> Inventory);
	UFUNCTION(BlueprintCallable)
	void SaveChestInventory(TArray<FString> Inventory);

	/*saving Progress*/
	UFUNCTION(BlueprintCallable)
	void SaveJournalCollected(TArray<FString> Collected);
	UFUNCTION(BlueprintCallable)
	void SaveBuildingGrade(FGameplayTag Building, int Grade);

	UFUNCTION(BlueprintCallable)
	FSavingStruct GetSavedVariable();
	UFUNCTION(BlueprintCallable)
	bool SetSavedVariable(FSavingStruct SavedStrct);
};
