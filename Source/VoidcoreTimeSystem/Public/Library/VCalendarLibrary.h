// Copyright (c) 2025 Ankit Bansal. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VCalendarLibrary.generated.h"

class UVCalendarDefinition;

struct FCalendarDate;

UCLASS(meta = (DisplayName = "Voidcore Calendar Library"))
class VOIDCORETIMESYSTEM_API UVCalendarLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    // Calendar Maths

    /** Returns true if A is equal to B (A == B) */
    UFUNCTION(BlueprintPure, Category = "Voidcore|Time|Calendar",
        meta = (DisplayName = "Equal (CalendarDate)", CompactNodeTitle = "==", Keywords = "== equal", ScriptMethod = "Equals", ScriptOperator = "=="))
    static bool EqualEqual_CalendarDate(const FCalendarDate& A, const FCalendarDate& B);

    /** Returns true if A is not equal to B (A != B) */
    UFUNCTION(BlueprintPure, Category = "Voidcore|Time|Calendar",
        meta = (DisplayName = "Not Equal (CalendarDate)", CompactNodeTitle = "!=", Keywords = "!= not equal", ScriptMethod = "NotEqual", ScriptOperator = "!="))
    static bool NotEqual_CalendarDate(const FCalendarDate& A, const FCalendarDate& B);

    /** Returns true if A is less than B (A < B) */
    UFUNCTION(BlueprintPure, Category = "Voidcore|Time|Calendar",
        meta = (DisplayName = "Less (CalendarDate)", CompactNodeTitle = "<", Keywords = "< less before earlier", ScriptOperator = "<"))
    static bool Less_CalendarDate(const FCalendarDate& A, const FCalendarDate& B);

    /** Returns true if A is less than or equal to B (A <= B) */
    UFUNCTION(BlueprintPure, Category = "Voidcore|Time|Calendar",
        meta = (DisplayName = "Less Equal (CalendarDate)", CompactNodeTitle = "<=", Keywords = "<= less equal before", ScriptOperator = "<="))
    static bool LessEqual_CalendarDate(const FCalendarDate& A, const FCalendarDate& B);

    /** Returns true if A is greater than B (A > B) */
    UFUNCTION(BlueprintPure, Category = "Voidcore|Time|Calendar",
        meta = (DisplayName = "Greater (CalendarDate)", CompactNodeTitle = ">", Keywords = "> greater after later", ScriptOperator = ">"))
    static bool Greater_CalendarDate(const FCalendarDate& A, const FCalendarDate& B);

    /** Returns true if A is greater than or equal to B (A >= B) */
    UFUNCTION(BlueprintPure, Category = "Voidcore|Time|Calendar",
        meta = (DisplayName = "Greater Equal (CalendarDate)", CompactNodeTitle = ">=", Keywords = ">= greater equal after", ScriptOperator = ">="))
    static bool GreaterEqual_CalendarDate(const FCalendarDate& A, const FCalendarDate& B);

    UFUNCTION(BlueprintPure, Category = "Voidcore|Time|Calendar",
        meta = (DisplayName = "Compare (CalendarDate)", Keywords = "compare sort"))
    static int32 Compare_CalendarDate(const FCalendarDate& A, const FCalendarDate& B);

    UFUNCTION(BlueprintPure, Category = "Voidcore|Time|Calendar",
        meta = (DisplayName = "Min (CalendarDate)", Keywords = "min earliest"))
    static FCalendarDate Min_CalendarDate(const FCalendarDate& A, const FCalendarDate& B);

    UFUNCTION(BlueprintPure, Category = "Voidcore|Time|Calendar",
        meta = (DisplayName = "Max (CalendarDate)", Keywords = "max latest"))
    static FCalendarDate Max_CalendarDate(const FCalendarDate& A, const FCalendarDate& B);

    // Calendar Factory

    UFUNCTION(BlueprintCallable, Category = "Voidcore|Time|Calendar")
    static FCalendarDate MakeCalendarDate(int32 Year, int32 DayOfYear);

    // Leap Year

    UFUNCTION(BlueprintCallable, Category = "Voidcore|Time|Calendar")
    static bool IsLeapYear(int32 Year, const UVCalendarDefinition* CalendarDefinition);
};
