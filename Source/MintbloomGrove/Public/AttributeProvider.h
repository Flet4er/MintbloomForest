// Copyright (c) Shining Games 2026

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AttributeProvider.generated.h"

/**
 * 
 */
UINTERFACE(MinimalAPI, NotBlueprintable)
class UAttributeProvider : public UInterface
{
    GENERATED_BODY()
};


class MINTBLOOMGROVE_API IAttributeProvider
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "Attributes")
    virtual float GetAttributeValue(const FGameplayTag& AttributeTag) const = 0;

};
