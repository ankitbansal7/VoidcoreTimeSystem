// Copyright (c) 2025 Ankit Bansal. All rights reserved.


#include "Core/VClockDefinition.h"

void UVClockDefinition::PostLoad()
{
    Super::PostLoad();
    Normalize();
}

#if WITH_EDITOR

void UVClockDefinition::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);
    Normalize();
}

#endif

int64 UVClockDefinition::GetSecondsPerHour() const
{
    return static_cast<int64>(MinutesPerHour) * static_cast<int64>(SecondsPerMinute);
}

int64 UVClockDefinition::GetSecondsPerDay() const
{
    return static_cast<int64>(HoursPerDay) * static_cast<int64>(MinutesPerHour) * static_cast<int64>(SecondsPerMinute);
}

int64 UVClockDefinition::GetMinutesPerDay() const
{
    return static_cast<int64>(HoursPerDay) * static_cast<int64>(MinutesPerHour);
}

void UVClockDefinition::Normalize()
{
    HoursPerDay = FMath::Max(1, HoursPerDay);
    MinutesPerHour = FMath::Max(1, MinutesPerHour);
    SecondsPerMinute = FMath::Max(1, SecondsPerMinute);
}
