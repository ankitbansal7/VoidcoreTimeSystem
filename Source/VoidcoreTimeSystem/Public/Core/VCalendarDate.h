// Copyright (c) 2025 Ankit Bansal. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "VCalendarDate.generated.h"

USTRUCT(BlueprintType, meta = (DisplayName = "Calendar Date"))
struct FVCalendarDate
{
    GENERATED_BODY()

public:
    FVCalendarDate() = default;
    FVCalendarDate(int32 InYear, int32 InDayOfYear);

    bool operator==(const FVCalendarDate& Other) const;
    bool operator!=(const FVCalendarDate& Other) const;
    bool operator<(const FVCalendarDate& Other) const;
    bool operator<=(const FVCalendarDate& Other) const;
    bool operator>(const FVCalendarDate& Other) const;
    bool operator>=(const FVCalendarDate& Other) const;

    friend inline uint32 GetTypeHash(const FVCalendarDate& Date)
    {
        return HashCombine(::GetTypeHash(Date.Year), ::GetTypeHash(Date.DayOfYear));
    }

public:
    // Canonical year index (allowing 0 and negatives keeps math simple and stable).
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, SaveGame, Category = "Calendar|Date")
    int32 Year{ 0 };

    // Canonical day-of-year (1-based).
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, SaveGame, Category = "Calendar|Date", meta = (ClampMin = "1"))
    int32 DayOfYear{ 1 };
};

template<>
struct TStructOpsTypeTraits<FVCalendarDate> : public TStructOpsTypeTraitsBase2<FVCalendarDate>
{
    enum
    {
        WithIdenticalViaEquality = true
    };
};

