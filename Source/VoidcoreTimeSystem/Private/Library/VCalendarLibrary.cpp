// Copyright (c) 2025 Ankit Bansal. All rights reserved.


#include "Library/VCalendarLibrary.h"
#include "Data/VCalendarDate.h"

bool UVCalendarLibrary::EqualEqual_CalendarDate(const FCalendarDate& A, const FCalendarDate& B)
{
    return (A == B);
}

bool UVCalendarLibrary::NotEqual_CalendarDate(const FCalendarDate& A, const FCalendarDate& B)
{
    return (A != B);
}

bool UVCalendarLibrary::Less_CalendarDate(const FCalendarDate& A, const FCalendarDate& B)
{
    return (A < B);
}

bool UVCalendarLibrary::LessEqual_CalendarDate(const FCalendarDate& A, const FCalendarDate& B)
{
    return (A <= B);
}

bool UVCalendarLibrary::Greater_CalendarDate(const FCalendarDate& A, const FCalendarDate& B)
{
    return (A > B);
}

bool UVCalendarLibrary::GreaterEqual_CalendarDate(const FCalendarDate& A, const FCalendarDate& B)
{
    return (A >= B);
}

int32 UVCalendarLibrary::Compare_CalendarDate(const FCalendarDate& A, const FCalendarDate& B)
{
    if (EqualEqual_CalendarDate(A, B))
    {
        return 0;
    }

    return (Less_CalendarDate(A, B) ? -1 : 1);
}

FCalendarDate UVCalendarLibrary::Min_CalendarDate(const FCalendarDate& A, const FCalendarDate& B)
{
    return Less_CalendarDate(A, B) ? A : B;
}

FCalendarDate UVCalendarLibrary::Max_CalendarDate(const FCalendarDate& A, const FCalendarDate& B)
{
    return Less_CalendarDate(A, B) ? B : A;
}

FCalendarDate UVCalendarLibrary::MakeCalendarDate(int32 Year, int32 DayOfYear)
{
    return FCalendarDate(Year, DayOfYear);
}
