// Copyright (c) 2025 Ankit Bansal. All rights reserved.

#include "Core/VClockTime.h"


FVClockTime::FVClockTime(int64 SecondsElapsed) :
    SecondsSinceEpoch(SecondsElapsed)
{
}

bool FVClockTime::operator==(const FVClockTime& Other) const
{
    return (SecondsSinceEpoch == Other.SecondsSinceEpoch);
}

bool FVClockTime::operator!=(const FVClockTime& Other) const
{
    return !(*this == Other);
}

bool FVClockTime::operator<(const FVClockTime& Other) const
{
    return (SecondsSinceEpoch < Other.SecondsSinceEpoch);
}

bool FVClockTime::operator<=(const FVClockTime& Other) const
{
    return ((*this < Other) || (*this == Other));
}

bool FVClockTime::operator>(const FVClockTime& Other) const
{
    return !(*this <= Other);
}

bool FVClockTime::operator>=(const FVClockTime& Other) const
{
    return !(*this < Other);
}
