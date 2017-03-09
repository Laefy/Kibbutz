#pragma once

/**
 * Handle all time related functions
 * Day/Night Cycle
 * In game clock
 */
class KIBBUTZ_API TimeManager
{
public:
	TimeManager();
	TimeManager(UWorld* World);

	void RotateSun(float DeltaSeconds);
	FString GetTime();
	FString FormatHourToString(int hours, int minutes);

	static const float SUN_SPEED;
	static const float DAY_DURATION_SECONDS;
	bool isNight = false;
	bool isPreviousFrameNight = false;
	int inGameMinutes = 0;
	int inGameHours = 0;

private:
	UWorld* WorldRef;
	ADirectionalLight *Sun = nullptr;
	AActor* SkySphere = nullptr;
	FRotator sunRotation;
};
