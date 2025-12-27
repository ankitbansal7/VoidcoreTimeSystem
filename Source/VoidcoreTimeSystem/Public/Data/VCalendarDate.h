#pragma once

#include "CoreMinimal.h"
#include "VCalendarDate.generated.h"

USTRUCT(BlueprintType)
struct FCalendarDate
{
    GENERATED_BODY()

public:
    FCalendarDate() = default;
    FCalendarDate(int32 InYear, int32 InDayOfYear);

    bool operator==(const FCalendarDate& Other) const;
    bool operator!=(const FCalendarDate& Other) const;
    bool operator<(const FCalendarDate& Other) const;
    bool operator<=(const FCalendarDate& Other) const;
    bool operator>(const FCalendarDate& Other) const;
    bool operator>=(const FCalendarDate& Other) const;

    friend inline uint32 GetTypeHash(const FCalendarDate& Date)
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
struct TStructOpsTypeTraits<FCalendarDate> : public TStructOpsTypeTraitsBase2<FCalendarDate>
{
    enum
    {
        WithIdenticalViaEquality = true
    };
};

