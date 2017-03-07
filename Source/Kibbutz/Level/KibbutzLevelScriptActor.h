// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/LevelScriptActor.h"
#include "KibbutzLevelScriptActor.generated.h"

/**
 * 
 */
UCLASS()
class KIBBUTZ_API AKibbutzLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	static const float SUN_SPEED;
	
private:
	ADirectionalLight *Sun = nullptr;
	AActor* SkySphere = nullptr;
	FRotator sunRotation;
	
};
