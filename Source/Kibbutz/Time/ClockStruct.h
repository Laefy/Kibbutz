#pragma once

#include "ClockStruct.generated.h"

USTRUCT()
struct KIBBUTZ_API FClockStruct {
	GENERATED_USTRUCT_BODY()

public:
	FClockStruct();
	FClockStruct(int _days, int _hours, int _minutes);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
		int days;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
		int hours;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
		int minutes;

	FORCEINLINE int operator-(FClockStruct const& other) const;

	FORCEINLINE void operator+=(int minutes);
};

FORCEINLINE int FClockStruct::operator-(FClockStruct const& other) const {
	return (minutes - other.minutes) + 60 * (hours - other.hours) + 60 * 24 * (days - other.days);
}

FORCEINLINE void FClockStruct::operator+=(int DeltaMinutes) {
	int NewMinutes = minutes + DeltaMinutes;
	int NewHours = hours + NewMinutes / 60;
	int NewDays = days + NewHours / 24;

	minutes = NewMinutes % 60;
	hours = NewHours % 24;
	days = NewDays;
}