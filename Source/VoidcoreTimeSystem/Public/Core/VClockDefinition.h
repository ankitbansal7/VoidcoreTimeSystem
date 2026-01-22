// Copyright (c) 2025 Ankit Bansal. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "VClockDefinition.generated.h"

UCLASS(BlueprintType, meta = (DisplayName = "Clock Definition"))
class VOIDCORETIMESYSTEM_API UVClockDefinition : public UDataAsset
{
    GENERATED_BODY()

public:
    virtual void PostLoad() override;

#if WITH_EDITOR
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

    UFUNCTION(BlueprintPure, Category = "Clock")
    int64 GetSecondsPerHour() const;

    UFUNCTION(BlueprintPure, Category = "Clock")
    int64 GetSecondsPerDay() const;

    UFUNCTION(BlueprintPure, Category = "Clock")
    int64 GetMinutesPerDay() const;

private:
    void Normalize();

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Clock", meta = (ClampMin = "1", UIMin = "1"))
    int32 HoursPerDay{ 24 };

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Clock", meta = (ClampMin = "1", UIMin = "1"))
    int32 MinutesPerHour{ 60 };

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Clock", meta = (ClampMin = "1", UIMin = "1"))
    int32 SecondsPerMinute{ 60 };
};
