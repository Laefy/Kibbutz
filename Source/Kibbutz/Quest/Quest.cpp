// Fill out your copyright notice in the Description page of Project Settings.

#include "Kibbutz.h"
#include "Quest.h"
#include "Player/MainController.h"


// Sets default values
AQuest::AQuest() {
	PrimaryActorTick.bCanEverTick = false;

	Advance = 0;
	Completed = false;
}

void AQuest::BeginPlay() {
	Super::BeginPlay();

	//Cast<AMainController>(GetWorld()->GetFirstPlayerController())->AddQuest(this);
}

bool AQuest::CheckAdvancement() {
	while (Advance < Steps.Num() && CheckStepCompleted(Advance)) {
		++ Advance;
	}

	UE_LOG(DebugLog, Error, TEXT("%d"), Advance);

	if (Advance == Steps.Num()) {
		Completed = true;
	}

	return Completed;
}

bool AQuest::CheckStepCompleted(int CurrentStep) {
	return false;
}
