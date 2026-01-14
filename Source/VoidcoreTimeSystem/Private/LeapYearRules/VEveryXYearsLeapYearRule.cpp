// Copyright (c) 2025 Ankit Bansal. All rights reserved.


#include "LeapYearRules/VEveryXYearsLeapYearRule.h"

UVEveryXYearsLeapYearRule::UVEveryXYearsLeapYearRule()
{
    RuleID = TEXT("EveryXYears");
}

bool UVEveryXYearsLeapYearRule::IsLeapYear_Implementation(int32 Year) const
{
    if (Year <= 0)
    {
        return false;
    }

    if (Interval <= 0)
    {
        return false;
    }

    return ((Year % Interval) == 0);
}

