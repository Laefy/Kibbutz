// Fill out your copyright notice in the Description page of Project Settings.

#include "Kibbutz.h"
#include "RepairHouse_Quest.h"

#include "Characters/MainCharacter.h"

// Sets default values
ARepairHouse_Quest::ARepairHouse_Quest() {
	Title = "Repair House";
	Description = "You just arrived in town, and you already got work to do ! "
				  "A villager's house has been vandalised, and there is a hole in his wall."
				  "You need to fix it.";

	Steps.Add("- Go to Carlos's house.");
	CompletedSteps.Add(false);

	Steps.Add("- Find the hole.");
	CompletedSteps.Add(false);

	Steps.Add("- Seek the toolbox you forgot home.");
	CompletedSteps.Add(false);

	Steps.Add("- Repair the broken plank using the crafting menu.");
	CompletedSteps.Add(false);

	Steps.Add("- Fix the hole.");
	CompletedSteps.Add(false);
}

void ARepairHouse_Quest::BeginPlay() {
	Super::BeginPlay();

	if (HouseArea != nullptr) {
		HouseArea->OnActorBeginOverlap.AddDynamic(this, &ARepairHouse_Quest::OnHouseAreaBeginOverlap);
	} else {
		UE_LOG(DebugLog, Error, TEXT("HouseArea was not specified for RepairHouse_Quest."));
	}
}

bool ARepairHouse_Quest::CheckStepCompleted(int CurrentStep) {
	return CompletedSteps[CurrentStep];
}

void ARepairHouse_Quest::OnHouseAreaBeginOverlap(AActor* OverlappedActor, AActor* OtherActor) {
	if (Cast<AMainCharacter>(OtherActor) != nullptr) {
		HouseArea->OnActorBeginOverlap.RemoveDynamic(this, &ARepairHouse_Quest::OnHouseAreaBeginOverlap);
		CompletedSteps[0] = true;
		CheckAdvancement();
	}
}
