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
	
protected:

	//Tick
	virtual void Tick(float DeltaSeconds) override;
	
	
};
