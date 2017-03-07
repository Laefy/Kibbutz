// Fill out your copyright notice in the Description page of Project Settings.

#include "Kibbutz.h"
#include "KibbutzLevelScriptActor.h"


const float AKibbutzLevelScriptActor::SUN_SPEED = 30;

void AKibbutzLevelScriptActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	ADirectionalLight* Sun = Cast<ADirectionalLight>(GetWorld()->SpawnActor(ADirectionalLight::StaticClass()));
	FRotator rotation;
	rotation.Pitch = SUN_SPEED * DeltaSeconds;
	rotation.Roll = 0.0f;
	rotation.Yaw = 0.0f;
	Sun->AddActorLocalRotation(rotation);
	
}
