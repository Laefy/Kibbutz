// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "Dialogues/DialogueManager.h"
#include "KibbutzGameMode.generated.h"


/**
 * The game mode.
 */
UCLASS()
class KIBBUTZ_API AKibbutzGameMode: public AGameMode {
	GENERATED_BODY()

public:
	// Constructor.
	AKibbutzGameMode();

	TMap<FString, TArray<FNPCStatement>> NPCStatementsMap;
};
