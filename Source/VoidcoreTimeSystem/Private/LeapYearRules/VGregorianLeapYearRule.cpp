// Copyright (c) 2025 Ankit Bansal. All rights reserved.


#include "LeapYearRules/VGregorianLeapYearRule.h"

UVGregorianLeapYearRule::UVGregorianLeapYearRule() 
{
    RuleID = TEXT("Gregorian");
}

bool UVGregorianLeapYearRule::IsLeapYear_Implementation(int32 Year) const
{
    if (Year <= 0)
    {
        return false;
    }

    return (((Year % 4) == 0) && (((Year % 100) != 0) || ((Year % 400) == 0)));
}
