// Copyright (c) Shining Games 2026


#include "MNTBLM_GameInstance.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetRenderingLibrary.h"

void UMNTBLM_GameInstance::Init()
{
	Super::Init();

	if (UGameplayStatics::DoesSaveGameExist(SaveSlot, 0))
	{
		SaveObject = Cast<UMNTBLM_SaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlot, 0));

		UE_LOG(LogTemp, Log, TEXT("LoadedSaveGame with name = %s"), *SaveObject->GetName());
	}
	else
	{
		USaveGame* save = UGameplayStatics::CreateSaveGameObject(UMNTBLM_SaveGame::StaticClass());
		UGameplayStatics::SaveGameToSlot(save, SaveSlot, 0);
		SaveObject = Cast<UMNTBLM_SaveGame>(save);
		UE_LOG(LogTemp, Log, TEXT("New slot created with name = %s"), *SaveObject->GetName());
	}
}

UMNTBLM_SaveGame* UMNTBLM_GameInstance::GetSaveGameObject()
{
	if (SaveObject)
	{
		return SaveObject;
	}
	else
	{
		SaveObject = Cast<UMNTBLM_SaveGame>(UGameplayStatics::CreateSaveGameObject(UMNTBLM_SaveGame::StaticClass()));
		UE_LOG(LogTemp, Log, TEXT("created save game for image name  = %s"), *SaveObject->GetName());
		return SaveObject;
	}
}

UMNTBLM_SaveGame* UMNTBLM_GameInstance::LoadGame(FString Slot)
{
	FString _SaveSlot;
	if (Slot.IsEmpty())
	{
		_SaveSlot = SaveSlot;
	}
	else
	{
		_SaveSlot = Slot;
	}
	if (UGameplayStatics::DoesSaveGameExist(_SaveSlot, 0))
	{
		SaveObject = Cast<UMNTBLM_SaveGame>(UGameplayStatics::LoadGameFromSlot(_SaveSlot, 0));
		UE_LOG(LogTemp, Log, TEXT("Loaded SaveGame for image with name = %s"), *SaveObject->GetName());
		return SaveObject;
	}
	else
	{
		SaveObject = Cast<UMNTBLM_SaveGame>(UGameplayStatics::CreateSaveGameObject(UMNTBLM_SaveGame::StaticClass()));
		UE_LOG(LogTemp, Log, TEXT("no save game for image, created with name  = %s"), *SaveObject->GetName());
		return SaveObject;
	}
}

void UMNTBLM_GameInstance::SaveGameSlot()
{
	if (SaveObject)
	{
		UGameplayStatics::SaveGameToSlot(SaveObject, SaveSlot, 0);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Error while saving primary slot. SaveObject is not valid"));
	}
}

void UMNTBLM_GameInstance::SaveCharacterLocation(FVector Location)
{
	GetSaveGameObject()->PawnLocation = Location;
}

void UMNTBLM_GameInstance::SaveCharacterInventory(TArray<FString> Inventory)
{
	GetSaveGameObject()->PawnInventory = Inventory;
}

void UMNTBLM_GameInstance::SaveCharacterStatus()
{
}

void UMNTBLM_GameInstance::SaveCookingPotInventory(TArray<FString> Inventory)
{
	GetSaveGameObject()->CoockingPotInventory = Inventory;
}

void UMNTBLM_GameInstance::SaveTeaPotInventory(TArray<FString> Inventory)
{
	GetSaveGameObject()->TeaPotInventory = Inventory;
}

void UMNTBLM_GameInstance::SaveChestInventory(TArray<FString> Inventory)
{
	GetSaveGameObject()->ChestInventory = Inventory;
}

void UMNTBLM_GameInstance::SaveJournalCollected(TArray<FString> Collected)
{
	GetSaveGameObject()->JournalCollected = Collected;
}

void UMNTBLM_GameInstance::SaveBuildingGrade(FGameplayTag Building, int Grade)
{
	GetSaveGameObject()->BuildingUpgrade.Add(Building, Grade);
}

FSavingStruct UMNTBLM_GameInstance::GetSavedVariable()
{
	UMNTBLM_SaveGame* SaveObj =  GetSaveGameObject();
	if (!SaveObj)
	{
		return FSavingStruct();
	}

	FSavingStruct RetStruct;

	RetStruct.BuildingUpgrade = SaveObj->BuildingUpgrade;
	RetStruct.ChestInventory = SaveObj->ChestInventory;
	RetStruct.CoockingPotInventory = SaveObj->CoockingPotInventory;
	RetStruct.JournalCollected = SaveObj->JournalCollected;
	RetStruct.PawnInventory = SaveObj->PawnInventory;
	RetStruct.PawnLocation = SaveObj->PawnLocation;
	RetStruct.TeaPotInventory = SaveObj->TeaPotInventory;
	return FSavingStruct();
}

bool UMNTBLM_GameInstance::SetSavedVariable(FSavingStruct SavedStrct)
{
	UMNTBLM_SaveGame* SaveObj = GetSaveGameObject();
	if (!SaveObj)
	{
		return false;
	}

	SaveObj->BuildingUpgrade = SavedStrct.BuildingUpgrade;
	SaveObj->ChestInventory = SavedStrct.ChestInventory;
	SaveObj->CoockingPotInventory = SavedStrct.CoockingPotInventory;
	SaveObj->JournalCollected = SavedStrct.JournalCollected;
	SaveObj->PawnInventory = SavedStrct.PawnInventory;
	SaveObj->PawnLocation = SavedStrct.PawnLocation;
	SaveObj->TeaPotInventory = SavedStrct.TeaPotInventory;
	return true;
};