// Fill out your copyright notice in the Description page of Project Settings.

#include "Kibbutz.h"
#include "FindChild_Quest.h"

#include "Characters/MainCharacter.h"

// Sets default values
AFindChild_Quest::AFindChild_Quest() {
	Title = "Find Chelsea's Child";
	Description = "Chelsea's son went missing. "
		"She thinks that he might be somewhere in the woods. "
		"You need to go find him ! ";

	Steps.Add("- Head for the woods.");
	CompletedSteps.Add(false);

	Steps.Add("- Find Chelsea's son.");
	CompletedSteps.Add(false);
}

void AFindChild_Quest::AddedToBook() {
	if (WoodArea != nullptr) {
		WoodArea->OnActorBeginOverlap.AddDynamic(this, &AFindChild_Quest::OnWoodsReached);
	} else {
		UE_LOG(DebugLog, Error, TEXT("WoodArea was not specified for FindChild_Quest."));
	}

	if (Child != nullptr && Cast<UPrimitiveComponent>(Child->GetRootComponent()) != nullptr) {
		Cast<UPrimitiveComponent>(Child->GetRootComponent())->OnComponentBeginOverlap.AddDynamic(this, &AFindChild_Quest::OnChildFound);
	} else {
		UE_LOG(DebugLog, Error, TEXT("Child was not specified for FindChild_Quest."));
	}
}

bool AFindChild_Quest::CheckStepCompleted(int CurrentStep) {
	return CurrentStep >= CompletedSteps.Num() || CompletedSteps[CurrentStep];
}

void AFindChild_Quest::OnWoodsReached(AActor* OverlappedActor, AActor* OtherActor) {
	if (Cast<AMainCharacter>(OtherActor) != nullptr) {
		WoodArea->OnActorBeginOverlap.RemoveDynamic(this, &AFindChild_Quest::OnWoodsReached);
		CompletedSteps[0] = true;
		CheckAdvancement();
	}
}

void AFindChild_Quest::OnChildFound(UPrimitiveComponent* Comp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) {
	if (Cast<AMainCharacter>(OtherActor) != nullptr) {
		Cast<UPrimitiveComponent>(Child->GetRootComponent())->OnComponentBeginOverlap.RemoveDynamic(this, &AFindChild_Quest::OnChildFound);
		CompletedSteps[1] = true;
		CheckAdvancement();
	}
}
