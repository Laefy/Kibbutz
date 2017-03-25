// Fill out your copyright notice in the Description page of Project Settings.

#include "Kibbutz.h"
#include "KibbutzGameMode.h"
#include "KibbutzHUD.h"
#include "Characters/MainCharacter.h"
#include "Player/MainController.h"

AKibbutzGameMode::AKibbutzGameMode() {
	HUDClass = AKibbutzHUD::StaticClass();

	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Characters/MainCharacterBP"));
	if (PlayerPawnBPClass.Class != NULL) {
		DefaultPawnClass = PlayerPawnBPClass.Class;
	} else {
		UE_LOG(DebugLog, Error, TEXT("Unable to find DefaultPawnClass."));
	}

	PlayerControllerClass = AMainController::StaticClass();
	NPCStatementsMap = UDialogueManager::LoadDialogues();
}

void AKibbutzGameMode::BeginPlay() {
	Super::BeginPlay();

	DayNightManager = GWorld->SpawnActor<ATimeManager>(ATimeManager::StaticClass());
}

void AKibbutzGameMode::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);
	Clock = DayNightManager->GetTime();

	// Re-activate if we need to trigger an event when night / day
	if (DayNightManager->isPreviousFrameNight != DayNightManager->isNight) {
		DayNightManager->isPreviousFrameNight = DayNightManager->isNight;

		if (!DayNightManager->isNight) {
			OnBecomeDay.Broadcast(Clock.days);
		}
	}
}

void AKibbutzGameMode::SetTime(FClockStruct const& Time) {
	DayNightManager->SetTime(Time);
	Clock = DayNightManager->GetTime();

	// Re-activate if we need to trigger an event when night / day
	if (DayNightManager->isPreviousFrameNight != DayNightManager->isNight) {
		DayNightManager->isPreviousFrameNight = DayNightManager->isNight;

		if (!DayNightManager->isNight) {
			OnBecomeDay.Broadcast(this->Clock.days);
		}
	}
}