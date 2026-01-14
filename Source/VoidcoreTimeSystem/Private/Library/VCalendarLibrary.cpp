// Copyright (c) 2025 Ankit Bansal. All rights reserved.


#include "Library/VCalendarLibrary.h"
#include "Core/VCalendarDate.h"
#include "Core/VCalendarDefinition.h"
#include "Core/VLeapYearRuleBase.h"

bool UVCalendarLibrary::EqualEqual_CalendarDate(const FVCalendarDate& A, const FVCalendarDate& B)
{
    return (A == B);
}

bool UVCalendarLibrary::NotEqual_CalendarDate(const FVCalendarDate& A, const FVCalendarDate& B)
{
    return (A != B);
}

bool UVCalendarLibrary::Less_CalendarDate(const FVCalendarDate& A, const FVCalendarDate& B)
{
    return (A < B);
}

bool UVCalendarLibrary::LessEqual_CalendarDate(const FVCalendarDate& A, const FVCalendarDate& B)
{
    return (A <= B);
}

bool UVCalendarLibrary::Greater_CalendarDate(const FVCalendarDate& A, const FVCalendarDate& B)
{
    return (A > B);
}

bool UVCalendarLibrary::GreaterEqual_CalendarDate(const FVCalendarDate& A, const FVCalendarDate& B)
{
    return (A >= B);
}

int32 UVCalendarLibrary::Compare_CalendarDate(const FVCalendarDate& A, const FVCalendarDate& B)
{
    if (EqualEqual_CalendarDate(A, B))
    {
        return 0;
    }

    return (Less_CalendarDate(A, B) ? -1 : 1);
}

FVCalendarDate UVCalendarLibrary::Min_CalendarDate(const FVCalendarDate& A, const FVCalendarDate& B)
{
    return Less_CalendarDate(A, B) ? A : B;
}

FVCalendarDate UVCalendarLibrary::Max_CalendarDate(const FVCalendarDate& A, const FVCalendarDate& B)
{
    return Less_CalendarDate(A, B) ? B : A;
}

FVCalendarDate UVCalendarLibrary::MakeCalendarDate(int32 Year, int32 DayOfYear)
{
    return FVCalendarDate(Year, DayOfYear);
}

bool UVCalendarLibrary::IsLeapYear(int32 Year, const UVCalendarDefinition* CalendarDefinition)
{
    if (!CalendarDefinition)
    {
        return false;
    }

    if (!CalendarDefinition->LeapYear.bLeapYearSupported)
    {
        return false;
    }

    const TSubclassOf<UVLeapYearRuleBase> RuleClass = CalendarDefinition->LeapYear.LeapYearRule;

    if (!RuleClass)
    {
        return false;
    }

    if (RuleClass->HasAnyClassFlags(CLASS_Abstract))
    {
        return false;
    }

    if (!RuleClass->IsChildOf(UVLeapYearRuleBase::StaticClass()))
    {
        return false;
    }

    const UVLeapYearRuleBase* RuleCDO = RuleClass->GetDefaultObject<UVLeapYearRuleBase>();

    if (!RuleCDO)
    {
        return false;
    }

    return RuleCDO->IsLeapYear(Year);
}
