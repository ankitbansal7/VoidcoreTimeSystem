// Copyright (c) 2025 Ankit Bansal. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "VClockTime.generated.h"

USTRUCT(BlueprintType, meta = (DisplayName = "Clock Time"))
struct FVClockTime
{
    GENERATED_BODY()

public:
    FVClockTime() = default;
    explicit FVClockTime(int64 SecondsElapsed);

    bool operator==(const FVClockTime& Other) const;
    bool operator!=(const FVClockTime& Other) const;
    bool operator<(const FVClockTime& Other) const;
    bool operator<=(const FVClockTime& Other) const;
    bool operator>(const FVClockTime& Other) const;
    bool operator>=(const FVClockTime& Other) const;

    friend inline uint32 GetTypeHash(const FVClockTime& Day)
    {
        return ::GetTypeHash(Day.SecondsSinceEpoch);
    }

public:
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, SaveGame, Category = "Clock|Time")
    int64 SecondsSinceEpoch{ 0 };
};

template<>
struct TStructOpsTypeTraits<FVClockTime> : public TStructOpsTypeTraitsBase2<FVClockTime>
{
    enum
    {
        WithIdenticalViaEquality = true
    };
};


