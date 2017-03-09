// Fill out your copyright notice in the Description page of Project Settings.

#include "Kibbutz.h"
#include "TimeManager.h"

const float TimeManager::SUN_SPEED = 10;
const float TimeManager::DAY_DURATION_SECONDS = 90;

TimeManager::TimeManager()
{
}

TimeManager::TimeManager(UWorld* World)
{
	WorldRef = World;
	for (TActorIterator<AActor> ActorItr(World); ActorItr; ++ActorItr)
	{
		if ((*ActorItr)->GetName().Equals("StaticMesh_SkySphere_2"))
		{
			this->SkySphere = *ActorItr;

			// quits the loop if both actors are found
			if (this->Sun != nullptr)
			{
				break;
			}
		}

		if ((*ActorItr)->GetName().Equals("DirectionalLightStationary_0"))
		{
			this->Sun = (ADirectionalLight*)(*ActorItr);

			// quits the loop if both actors are found
			if (this->SkySphere != nullptr)
			{
				break;
			}
		}
	}
}

void TimeManager::RotateSun(float DeltaSeconds)
{
	this->sunRotation.Pitch = SUN_SPEED * DeltaSeconds;
	this->sunRotation.Roll = 0.0f;
	this->sunRotation.Yaw = 0.0f;
	this->Sun->AddActorLocalRotation(this->sunRotation);

	FOutputDeviceNull ar;
	this->SkySphere->CallFunctionByNameWithArguments(TEXT("UpdateSunDirection"), ar, NULL, true);

	float sunAngle = this->Sun->GetActorRotation().Clamp().Pitch;
	if (sunAngle > 0 && sunAngle < 180) {
		this->isNight = true;		
	}
	else {
		this->isNight = false;
	}

}

FString TimeManager::GetTime()
{
	// Real time 1min30 = 1 hour In game
	// Real time 90s = 60min In game
	// Real time 1s = 60/90min In game
	float realtimeSeconds = UGameplayStatics::GetRealTimeSeconds(WorldRef);
	inGameMinutes = floor(realtimeSeconds*(60 / DAY_DURATION_SECONDS)) - (60 * inGameHours);
	if (inGameMinutes > 59) {
			inGameMinutes = 0;
			inGameHours += 1;
	}
	// TODO Add days 
	return FormatHourToString(inGameHours, inGameMinutes);
}


FString TimeManager::FormatHourToString(int hours, int minutes) {
	// Ugly af, sorry
	FString result;
	if (hours < 10) {
		result = "0" + FString::FromInt(hours);
	}
	else {
		result = FString::FromInt(hours);
	}
	if (minutes < 10) {
		result += " : 0" + FString::FromInt(minutes);
	}
	else {
		result += " : " + FString::FromInt(minutes);
	}

	return result;
}