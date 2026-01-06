// Copyright (c) 2025 Ankit Bansal. All rights reserved.


#include "Data/EveryXYearsLeapYearRule.h"

UEveryXYearsLeapYearRule::UEveryXYearsLeapYearRule()
{
    RuleID = TEXT("EveryXYears");
}

bool UEveryXYearsLeapYearRule::IsLeapYear_Implementation(int32 Year) const
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

