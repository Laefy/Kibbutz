#pragma once

#include "GameFramework/Actor.h"
#include "ClockStruct.h"

#include "TimeManager.generated.h"

/**
* Handle all time related functions
* Day/Night Cycle
* In game clock
*/
UCLASS()
class KIBBUTZ_API ATimeManager: public AActor {
	GENERATED_BODY()

public:
	ATimeManager();

	// Override AActor::Tick.
	virtual void Tick(float DeltaTime) override;

	// Override AActor::BeginPlay.
	virtual void BeginPlay() override;

	//FString FormatDateToString(int days, int hours, int minutes);

	static const float SUN_SPEED;
	static const float DAY_DURATION_SECONDS;

	FORCEINLINE FClockStruct GetTime() const;
	FORCEINLINE void SetTime(FClockStruct const& Time);

	bool bBlocked;

private:
	ADirectionalLight *Sun = nullptr;
	AActor* SkySphere = nullptr;
	FRotator SunRotation;

	FClockStruct Clock;
	float DeltaSeconds;

};

FORCEINLINE void ATimeManager::SetTime(FClockStruct const& Time) {
	Tick((Time - Clock) / 5.f);
}

FORCEINLINE FClockStruct ATimeManager::GetTime() const {
	return Clock;
}
