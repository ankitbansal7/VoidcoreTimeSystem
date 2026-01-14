// Copyright (c) 2025 Ankit Bansal. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/VLeapYearRuleBase.h"
#include "VGregorianLeapYearRule.generated.h"

UCLASS(Blueprintable, BlueprintType, meta = (DisplayName = "Gregorian Leap Year Rule"))
class VOIDCORETIMESYSTEM_API UVGregorianLeapYearRule : public UVLeapYearRuleBase
{
    GENERATED_BODY()

public:
    UVGregorianLeapYearRule();
    virtual bool IsLeapYear_Implementation(int32 Year) const override;
};
