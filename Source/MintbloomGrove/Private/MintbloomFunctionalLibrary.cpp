// Copyright (c) Shining Games 2026


#include "MintbloomFunctionalLibrary.h"
#include "DTStruct.h"
#include "GameplayTagsManager.h"
#include "GameplayTagContainer.h"

bool UMintbloomFunctionalLibrary::GetPlayInEditor()
{
#if WITH_EDITOR
    return true;
#else
    return false;
#endif
}

FIconRow UMintbloomFunctionalLibrary::GetIconRow(FString IconName)
{
    if (IconName.IsEmpty()) return FIconRow();


    static UDataTable* IconTable = LoadObject<UDataTable>(nullptr, TEXT("DataTable'/Game/_Mintbloom/DT/ICOItem_DT.ICOItem_DT'"));
    if (!IconTable) return FIconRow();

    FName RowName = FName(IconName);
    const FIconRow* Row = IconTable->FindRow<FIconRow>(RowName, TEXT("GetIconRow"));
    if (!Row) return FIconRow();

    return *Row;
}

FGameplayTagContainer UMintbloomFunctionalLibrary::GetAllCollectableItem(FGameplayTag ParentTag)
{
    FGameplayTagContainer Result;
    FGameplayTagContainer ChildTags;
    ChildTags = UGameplayTagsManager::Get().RequestGameplayTagChildren(ParentTag);

    for (const FGameplayTag& Tag : ChildTags)
    {
        FGameplayTag DirectParent = Tag.RequestDirectParent();

        if (DirectParent == ParentTag)
        {
            Result.AddTag(Tag);
        }
    }
    Result.RemoveTag(ParentTag);
    return Result;
}