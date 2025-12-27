#include "Data/VCalendarDate.h"

FCalendarDate::FCalendarDate(int32 InYear, int32 InDayOfYear) :
    Year(InYear),
    DayOfYear(InDayOfYear)
{
}

bool FCalendarDate::operator==(const FCalendarDate& Other) const
{
    return (Year == Other.Year) && (DayOfYear == Other.DayOfYear);
}

bool FCalendarDate::operator!=(const FCalendarDate& Other) const
{
    return !(*this == Other);
}

bool FCalendarDate::operator<(const FCalendarDate& Other) const
{
    return (Year < Other.Year) || ((Year == Other.Year) && (DayOfYear < Other.DayOfYear));
}

bool FCalendarDate::operator<=(const FCalendarDate& Other) const
{
    return ((*this < Other) || (*this == Other));
}

bool FCalendarDate::operator>(const FCalendarDate& Other) const
{
    return !(*this <= Other);
}

bool FCalendarDate::operator>=(const FCalendarDate& Other) const
{
    return !(*this < Other);
}
