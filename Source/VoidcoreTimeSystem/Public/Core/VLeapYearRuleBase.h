// Copyright (c) 2025 Ankit Bansal. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "VLeapYearRuleBase.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType, meta = (DisplayName = "Leap Year Rule Base"))
class VOIDCORETIMESYSTEM_API UVLeapYearRuleBase : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category = "Voidcore|Calendar|LeapYear")
    bool IsLeapYear(int32 Year) const;

    virtual bool IsLeapYear_Implementation(int32 Year) const { return false; } // C++ default implementation

    FORCEINLINE FName GetRuleID() const { return RuleID; }

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Calendar|LeapYear")
    FName RuleID{ NAME_None };
};
