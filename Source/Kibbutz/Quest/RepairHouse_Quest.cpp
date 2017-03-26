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

	Steps.Add("- Go to Carlos's house and look for the hole.");
	CompletedSteps.Add(false);

	//Steps.Add("- Find the hole.");
	//CompletedSteps.Add(false);

	Steps.Add("- Seek the toolbox you forgot home.");
	CompletedSteps.Add(false);

	Steps.Add("- Repair the broken plank using the crafting menu.");
	CompletedSteps.Add(false);

	Steps.Add("- Fix the hole.");
	CompletedSteps.Add(false);

	UE_LOG(DebugLog, Warning, TEXT("Quest initialized."));

}

void ARepairHouse_Quest::BeginPlay() {
	Super::BeginPlay();

	if (HeroHouseArea != nullptr) {
		HeroHouseArea->OnActorBeginOverlap.AddDynamic(this, &ARepairHouse_Quest::OnHeroHouseAreaBeginOverlap);
	} else {
		UE_LOG(DebugLog, Error, TEXT("HeroHouseArea was not specified for RepairHouse_Quest."));
	}

	if (WoodcutterHouseArea != nullptr) {
		WoodcutterHouseArea->OnActorBeginOverlap.AddDynamic(this, &ARepairHouse_Quest::OnWoodcutterHouseAreaBeginOverlap);
	}
	else {
		UE_LOG(DebugLog, Error, TEXT("WoodcutterHouseArea was not specified for RepairHouse_Quest."));
	}

	UE_LOG(DebugLog, Warning, TEXT("BeginPlay launched"));

}

bool ARepairHouse_Quest::CheckStepCompleted(int CurrentStep) {
	UE_LOG(DebugLog, Warning, TEXT("Step filled."));
	return CompletedSteps[CurrentStep];
}

void ARepairHouse_Quest::OnWoodcutterHouseAreaBeginOverlap(AActor* OverlappedActor, AActor* OtherActor) {
	if (Cast<AMainCharacter>(OtherActor) != nullptr) {
		WoodcutterHouseArea->OnActorBeginOverlap.RemoveDynamic(this, &ARepairHouse_Quest::OnWoodcutterHouseAreaBeginOverlap);
		CompletedSteps[0] = true;
		CheckAdvancement();
	}
}

void ARepairHouse_Quest::OnHeroHouseAreaBeginOverlap(AActor* OverlappedActor, AActor* OtherActor) {
	if (CompletedSteps[0] == true && Cast<AMainCharacter>(OtherActor) != nullptr) {
		HeroHouseArea->OnActorBeginOverlap.RemoveDynamic(this, &ARepairHouse_Quest::OnHeroHouseAreaBeginOverlap);
		CompletedSteps[1] = true;
		CheckAdvancement();
	}
}