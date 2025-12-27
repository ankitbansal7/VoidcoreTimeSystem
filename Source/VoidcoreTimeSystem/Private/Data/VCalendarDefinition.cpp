// Copyright (c) 2025 Ankit Bansal. All rights reserved.


#include "Data/VCalendarDefinition.h"

#include "Misc/DataValidation.h"

#if WITH_EDITOR
EDataValidationResult UVCalendarDefinition::IsDataValid(FDataValidationContext& Context) const
{
    bool bHasErrors = false;

    if (Months.Num() == 0)
    {
        Context.AddError(FText::FromString("Calendar must contain at least one month."));
        bHasErrors = true;
    }


    if (WeekDays.Num() == 0)
    {
        Context.AddError(FText::FromString("Calendar must contain at least one weekday."));
        bHasErrors = true;
    }

    if (CalendarStartWeekDayIndex < 0 || CalendarStartWeekDayIndex >= WeekDays.Num())
    {
        Context.AddError(FText::FromString("CalendarStartWeekDayIndex is out of range for the defined weekdays."));
        bHasErrors = true;
    }

    if (LeapYear.bLeapYearSupported)
    {
        bool bAnyLeapMonth = false;

        for (const FMonthDefinition& Month : Months)
        {
            if (Month.bCanLeap)
            {
                bAnyLeapMonth = true;
                break;
            }
        }

        if (!bAnyLeapMonth)
        {
            Context.AddWarning(FText::FromString("Leap years are enabled, but no month supports leap days."));
        }
    }

    return (bHasErrors ? EDataValidationResult::Invalid : EDataValidationResult::Valid);
}
#endif // WITH_EDITOR
