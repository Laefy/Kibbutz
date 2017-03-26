// Fill out your copyright notice in the Description page of Project Settings.

#include "Kibbutz.h"
#include "TimeManager.h"
#include "Kismet/KismetMathLibrary.h"

// TODO : Would be better if we could link those two so it's more dynamic
const float ATimeManager::SUN_SPEED = 0.09;
const float ATimeManager::DAY_DURATION_SECONDS = 90;

ATimeManager::ATimeManager() {
	PrimaryActorTick.bCanEverTick = true;

	Clock = FClockStruct(1, 8, 0);
	DeltaSeconds = 0;
	bBlocked = false;
}

void ATimeManager::BeginPlay() {
	Super::BeginPlay();

	for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr) {
		if ((*ActorItr)->GetName().Equals("StaticMesh_SkySphere_2")) {
			this->SkySphere = *ActorItr;

			// quits the loop if both actors are found
			if (this->Sun != nullptr) {
				break;
			}
		}

		if ((*ActorItr)->GetName().Equals("DirectionalLightStationary_0")) {
			this->Sun = (ADirectionalLight*)(*ActorItr);

			// quits the loop if both actors are found
			if (this->SkySphere != nullptr) {
				break;
			}
		}
	}
}

void ATimeManager::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (bBlocked) {
		return;
	}

	DeltaSeconds += DeltaTime;
	Clock += DeltaSeconds;

	DeltaSeconds = FMath::Fmod(DeltaSeconds, 1.f);

	if (Sun) {
		FRotator Rotation = Sun->GetActorRotation();
		Rotation.Pitch = FMath::Fmod(((Clock.hours + Clock.minutes / 60.f) + 30.f) * 360.f / 24.f, 360.f);
		Rotation.Yaw = 0;
		Rotation.Roll = 0;

		Sun->SetActorRotation(Rotation);

		FOutputDeviceNull ar;
		SkySphere->CallFunctionByNameWithArguments(TEXT("UpdateSunDirection"), ar, NULL, true);

		float sunAngle = Sun->GetActorRotation().Clamp().Pitch;
		if (sunAngle > 0 && sunAngle < 180) {
			this->isNight = true;
		} else {
			this->isNight = false;
		}
	}
}
