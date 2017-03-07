// Fill out your copyright notice in the Description page of Project Settings.

#include "Kibbutz.h"
#include "KibbutzLevelScriptActor.h"

const float AKibbutzLevelScriptActor::SUN_SPEED = 10;

void AKibbutzLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();

	for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
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

void AKibbutzLevelScriptActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	this->sunRotation.Pitch = SUN_SPEED * DeltaSeconds;
	this->sunRotation.Roll = 0.0f;
	this->sunRotation.Yaw = 0.0f;
	this->Sun->AddActorLocalRotation(this->sunRotation);

	FOutputDeviceNull ar;
	this->SkySphere->CallFunctionByNameWithArguments(TEXT("UpdateSunDirection"), ar, NULL, true);

	float sunAngle = this->Sun->GetActorRotation().Clamp().Pitch;
	if (sunAngle > 0 && sunAngle < 180) {
		UE_LOG(LogTemp, Warning, TEXT("NIGHT"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("DAY"));
	}


}

