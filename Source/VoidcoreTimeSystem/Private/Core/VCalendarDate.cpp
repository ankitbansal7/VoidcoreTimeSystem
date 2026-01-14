// Copyright (c) 2025 Ankit Bansal. All rights reserved.


#include "Core/VCalendarDate.h"

FVCalendarDate::FVCalendarDate(int32 InYear, int32 InDayOfYear) :
    Year(InYear),
    DayOfYear(InDayOfYear)
{
}

bool FVCalendarDate::operator==(const FVCalendarDate& Other) const
{
    return (Year == Other.Year) && (DayOfYear == Other.DayOfYear);
}

bool FVCalendarDate::operator!=(const FVCalendarDate& Other) const
{
    return !(*this == Other);
}

bool FVCalendarDate::operator<(const FVCalendarDate& Other) const
{
    return (Year < Other.Year) || ((Year == Other.Year) && (DayOfYear < Other.DayOfYear));
}

bool FVCalendarDate::operator<=(const FVCalendarDate& Other) const
{
    return ((*this < Other) || (*this == Other));
}

bool FVCalendarDate::operator>(const FVCalendarDate& Other) const
{
    return !(*this <= Other);
}

bool FVCalendarDate::operator>=(const FVCalendarDate& Other) const
{
    return !(*this < Other);
}
