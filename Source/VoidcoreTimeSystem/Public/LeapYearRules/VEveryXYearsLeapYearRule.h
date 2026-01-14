// Copyright (c) 2025 Ankit Bansal. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/VLeapYearRuleBase.h"
#include "VEveryXYearsLeapYearRule.generated.h"

UCLASS(Blueprintable, BlueprintType, meta = (DisplayName = " Every X Years Leap Year Rule"))
class VOIDCORETIMESYSTEM_API UVEveryXYearsLeapYearRule : public UVLeapYearRuleBase
{
    GENERATED_BODY()

public:
    UVEveryXYearsLeapYearRule();
    virtual bool IsLeapYear_Implementation(int32 Year) const override;

    FORCEINLINE int32 GetInterval() const { return Interval; }

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Calendar|LeapYear")
    int32 Interval{ 4 }; // Default to every 4 years, like basic leap, modify in derived class
};
