#pragma once
#include "ClockStruct.generated.h"
/**
 * 
 */
USTRUCT()
struct KIBBUTZ_API FClockStruct
{
	GENERATED_USTRUCT_BODY()
public:
	FClockStruct();
	FClockStruct(int _days, int _hours, int _minutes);
	~FClockStruct();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	int days;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	int hours;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	int minutes;
};
