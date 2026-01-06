// Copyright (c) 2025 Ankit Bansal. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Data/LeapYearRule.h"
#include "GregorianLeapYearRule.generated.h"

UCLASS(Blueprintable, BlueprintType)
class VOIDCORETIMESYSTEM_API UGregorianLeapYearRule : public ULeapYearRule
{
    GENERATED_BODY()

public:
    UGregorianLeapYearRule();
    virtual bool IsLeapYear_Implementation(int32 Year) const override;
};
