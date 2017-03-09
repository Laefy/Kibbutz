// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class KIBBUTZ_API TimeManager
{
public:
	TimeManager();
	TimeManager(UWorld* World);

	void RotateSun(float DeltaSeconds);
	static const float SUN_SPEED;
	bool isNight = false;
	bool isPreviousFrameNight = false;
private:
	ADirectionalLight *Sun = nullptr;
	AActor* SkySphere = nullptr;
	FRotator sunRotation;
	
};
