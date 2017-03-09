// Fill out your copyright notice in the Description page of Project Settings.

#include "Kibbutz.h"
#include "KibbutzLevelScriptActor.h"


void AKibbutzLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();

	this->DayNightManager = new TimeManager(GetWorld());
}

void AKibbutzLevelScriptActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	this->DayNightManager->RotateSun(DeltaSeconds);
	
	if (this->DayNightManager->isPreviousFrameNight != this->DayNightManager->isNight) {
		this->DayNightManager->isPreviousFrameNight = this->DayNightManager->isNight;

		if (this->DayNightManager->isNight) {
			this->BecomeNight();
		}
		else {
			this->BecomeDay();
		}

	}
}

