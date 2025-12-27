// Copyright (c) 2025 Ankit Bansal. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "VCalendarDefinition.generated.h"

/**
 * How a season is defined over the year.
 * - MonthRange: season covers whole months (most common in games)
 * - DayOfYearRange: season covers a day-of-year interval (more precise)
 */
UENUM(BlueprintType)
enum class EVSeasonCoverageType : uint8
{
    MonthRange    UMETA(DisplayName = "Month Range"),
    DayOfYearRange UMETA(DisplayName = "Day-Of-Year Range"),
};

UENUM(BlueprintType, meta = (DisplayName = "Leap Year Rule"))
enum class ELeapYearRule : uint8
{
    /** Standard Gregorian calendar leap year rules. */
    Gregorian UMETA(DisplayName = "Gregorian"),

    /** Every Xth year is a leap year (e.g., every 5 years). */
    EveryXYears UMETA(DisplayName = "Every X Years"),

    /** Uses a custom leap year rule. */
    Custom UMETA(DisplayName = "Custom Rule")
};

USTRUCT(BlueprintType)
struct FCalendarPeriodDescriptor
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

USTRUCT(BlueprintType)
struct FMonthDefinition
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|Month")
    FCalendarPeriodDescriptor Descriptor;

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

USTRUCT(BlueprintType)
struct FWeekDayDefinition
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|Week")
    FCalendarPeriodDescriptor Descriptor;

    // Optional helper flag; mark “rest day” / “weekend”
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|Week")
    bool bIsRestDay = false;
};

USTRUCT(BlueprintType)
struct FLeapYearDefinition
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|LeapYear",
        meta = (DisplayName = "Support Leap Years", ToolTip = "Does the Calendar Support Leap Years?"))
    bool bLeapYearSupported{ false };

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|LeapYear",
        meta = (EditCondition = "bLeapYearSupported", EditConditionHides))
    ELeapYearRule LeapYearRule{ ELeapYearRule::Gregorian };

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|LeapYear",
        meta = (ClampMin = "1", UIMin = "1", EditCondition = "(bLeapYearSupported && (LeapYearRule == ELeapYearRule::EveryXYears))", EditConditionHides))
    int32 LeapYearInterval{ 4 };

    // Leap if: (Year - LeapYearOffset) % LeapYearInterval == 0
    // Example: Interval=5, Offset=3 -> leap years: 3, 8, 13, ...
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|LeapYear",
        meta = (ClampMin = "0", UIMin = "0", EditCondition = "(bLeapYearSupported && (LeapYearRule == ELeapYearRule::EveryXYears))", EditConditionHides))
    int32 LeapYearOffset{ 0 };

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|LeapYear",
        meta = (EditCondition = "(bLeapYearSupported && (LeapYearRule == ELeapYearRule::Custom))", EditConditionHides))
    FName CustomRuleId{ NAME_None };
};


/**
 * Defines a "season" as a named overlay classification on top of a calendar year.
 * Seasons are NOT a time unit like months; they are a mapping from day-of-year to a label.
 */
USTRUCT(BlueprintType)
struct FSeasonDefinition
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|Season")
    FCalendarPeriodDescriptor Descriptor;

    // How this season's span is defined.
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|Season")
    EVSeasonCoverageType CoverageType = EVSeasonCoverageType::MonthRange;

    /**
     * MonthRange: inclusive start month index in the calendar's Months array.
     * Example: Spring = 2 (March if Months[0]=January)
     */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|Season",
        meta = (EditCondition = "CoverageType==EVSeasonCoverageType::MonthRange", EditConditionHides, ClampMin = "0"))
    int32 StartMonthIndex = 0;

    /**
     * MonthRange: inclusive end month index in the calendar's Months array.
     * Can be < StartMonthIndex to indicate wrap-around (e.g., Winter: Dec->Feb).
     */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|Season",
        meta = (EditCondition = "CoverageType==EVSeasonCoverageType::MonthRange", EditConditionHides, ClampMin = "0"))
    int32 EndMonthIndex = 0;

    /**
     * DayOfYearRange: inclusive start day-of-year (1-based).
     * Example: 1 means first day of the year.
     */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|Season",
        meta = (EditCondition = "CoverageType==EVSeasonCoverageType::DayOfYearRange", EditConditionHides, ClampMin = "1"))
    int32 StartDayOfYear = 1;

    /**
     * DayOfYearRange: inclusive end day-of-year (1-based).
     * Can be < StartDayOfYear to indicate wrap-around (e.g., Winter spans year end).
     */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|Season",
        meta = (EditCondition = "CoverageType==EVSeasonCoverageType::DayOfYearRange", EditConditionHides, ClampMin = "1"))
    int32 EndDayOfYear = 1;

    /**
     * Optional: If true, this season is intended to cover the "remaining" days not covered by other seasons.
     * This is purely declarative metadata; how it's used is up to the consumer.
     *
     * Keep false if you want seasons to be explicitly defined and non-overlapping.
     */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar|Season")
    bool bIsFallbackSeason = false;
};

UCLASS(BlueprintType)
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
    TArray<FMonthDefinition> Months;

    // Ordered list of all weekdays in the repeating week cycle.
    // The first element (index 0) is the first day of the week.
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar")
    TArray<FWeekDayDefinition> WeekDays;

    // List of seasons possible
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar")
    TArray<FSeasonDefinition> Seasons;

    // leap year rules
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar")
    FLeapYearDefinition LeapYear;

    // Index into WeekDays array indicating which weekday was the day
    // of Year 1, Month 1 (i.e., Months[0]), Day 1.
    // Valid range: 0 to WeekDays.Num()-1
    // Example: 0 = first day in WeekDays array, 1 = second, etc.
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar", meta = (ClampMin = "0", UIMin = "0"))
    int32 CalendarStartWeekDayIndex{ 0 };
};

