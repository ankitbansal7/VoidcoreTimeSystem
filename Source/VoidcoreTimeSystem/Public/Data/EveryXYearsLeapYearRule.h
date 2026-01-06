// Copyright (c) 2025 Ankit Bansal. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Data/LeapYearRule.h"
#include "EveryXYearsLeapYearRule.generated.h"

UCLASS(Blueprintable, BlueprintType)
class VOIDCORETIMESYSTEM_API UEveryXYearsLeapYearRule : public ULeapYearRule
{
    GENERATED_BODY()

public:
    UEveryXYearsLeapYearRule();
    virtual bool IsLeapYear_Implementation(int32 Year) const override;

    FORCEINLINE int32 GetInterval() const { return Interval; }

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Calendar|LeapYear")
    int32 Interval{ 4 }; // Default to every 4 years, like basic leap, modify in derived class
};
