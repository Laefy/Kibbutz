// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "Dialogues/DialogueManager.h"
#include "Time/TimeManager.h"
#include "Time/ClockStruct.h"
#include "KibbutzGameMode.generated.h"


/**
* The game mode.
*/
UCLASS()
class KIBBUTZ_API AKibbutzGameMode : public AGameMode {
	GENERATED_BODY()

public:
	// Constructor.
	AKibbutzGameMode();

	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Time)
		FClockStruct Clock;

	TMap<FString, TArray<FNPCStatement>> NPCStatementsMap;

private:
	TimeManager* DayNightManager;
};