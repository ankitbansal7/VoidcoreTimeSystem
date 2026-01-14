// Copyright (c) 2025 Ankit Bansal. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "VCalendarDefinition.generated.h"

class UVLeapYearRuleBase;

USTRUCT(BlueprintType, meta = (DisplayName = "Calendar Period Descriptor"))
struct FVCalendarPeriodDescriptor
{
    GENERATED_BODY()

public:
    // Stable internal identifier (non-localized)
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|Meta")
    FName Id{ NAME_None };

    // Display name (localized)
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|Meta")
    FText DisplayName;

    // Optional description (localized)
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|Meta", meta = (MultiLine = "true"))
    FText Description;

    // Optional associated patron (localized)
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|Meta")
    FText AssociatedPatron;

    // Optional UI color
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|Meta")
    FLinearColor Color{ FLinearColor::White };

    // Optional icon
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|Meta")
    TSoftObjectPtr<UTexture2D> Icon{ nullptr };
};

USTRUCT(BlueprintType, meta = (DisplayName = "Calendar Month Definition"))
struct FVMonthDefinition
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|Month")
    FVCalendarPeriodDescriptor Descriptor;

    // Number of days in this month/segment.
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|Month", meta = (ClampMin = "1", UIMin = "1"))
    int32 NumDays = 30;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|Month")
    bool bCanLeap{ false };

    // Only applied if bCanLeap is true
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|Month",
        meta = (ClampMin = "1", UIMin = "1", EditCondition = "bCanLeap", EditConditionHides))
    int32 NumLeapDays{ 1 };
};

USTRUCT(BlueprintType, meta = (DisplayName = "Calendar Week Day Definition"))
struct FVWeekDayDefinition
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|Week")
    FVCalendarPeriodDescriptor Descriptor;

    // Optional helper flag; mark “rest day” / “weekend”
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|Week")
    bool bIsRestDay = false;
};

USTRUCT(BlueprintType, meta = (DisplayName = "Calendar Leap Year Definition"))
struct FVLeapYearDefinition
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|LeapYear",
        meta = (DisplayName = "Support Leap Years", ToolTip = "Does the Calendar Support Leap Years?"))
    bool bLeapYearSupported{ false };

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|LeapYear",
        meta = (EditCondition = "bLeapYearSupported", EditConditionHides))
    TSubclassOf<UVLeapYearRuleBase> LeapYearRule{ nullptr };
};

UCLASS(BlueprintType, meta = (DisplayName = "Calendar Definition"))
class VOIDCORETIMESYSTEM_API UVCalendarDefinition : public UDataAsset
{
    GENERATED_BODY()

public:
#if WITH_EDITOR
    virtual EDataValidationResult IsDataValid(FDataValidationContext& Context) const override;
#endif // WITH_EDITOR

public:
    UFUNCTION(BlueprintPure, Category = "Calendar")
    int32 GetMonthsPerYear() const { return Months.Num(); }

    UFUNCTION(BlueprintPure, Category = "Calendar")
    int32 GetDaysPerWeek() const { return WeekDays.Num(); }

public:
    // Ordered list of all months in the year.
    // The first element (index 0) is the first month of the year.
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar")
    TArray<FVMonthDefinition> Months;

    // Ordered list of all weekdays in the repeating week cycle.
    // The first element (index 0) is the first day of the week.
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar")
    TArray<FVWeekDayDefinition> WeekDays;

    // leap year rules
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar")
    FVLeapYearDefinition LeapYear;

    // Index into WeekDays array indicating which weekday was the day
    // of Year 1, Month 1 (i.e., Months[0]), Day 1.
    // Valid range: 0 to WeekDays.Num()-1
    // Example: 0 = first day in WeekDays array, 1 = second, etc.
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar", meta = (ClampMin = "0", UIMin = "0"))
    int32 CalendarStartWeekDayIndex{ 0 };
};

