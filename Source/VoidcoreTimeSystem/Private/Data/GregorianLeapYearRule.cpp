// Copyright (c) 2025 Ankit Bansal. All rights reserved.


#include "Data/GregorianLeapYearRule.h"

UGregorianLeapYearRule::UGregorianLeapYearRule() 
{
    RuleID = TEXT("Gregorian");
}

bool UGregorianLeapYearRule::IsLeapYear_Implementation(int32 Year) const
{
    if (Year <= 0)
    {
        return false;
    }

    return (((Year % 4) == 0) && (((Year % 100) != 0) || ((Year % 400) == 0)));
}
