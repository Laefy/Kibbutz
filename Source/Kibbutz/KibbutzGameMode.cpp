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

void AKibbutzGameMode::BeginPlay()
{
	Super::BeginPlay();
	this->DayNightManager = new TimeManager(GetWorld());
}

void AKibbutzGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	this->DayNightManager->RotateSun(DeltaSeconds);
	this->Clock = this->DayNightManager->GetTime();

	// Re-activate if we need to trigger an event when night / day
	if (this->DayNightManager->isPreviousFrameNight != this->DayNightManager->isNight) {
		this->DayNightManager->isPreviousFrameNight = this->DayNightManager->isNight;

		if (!this->DayNightManager->isNight) {
			this->OnBecomeDay.Broadcast(this->Clock.days);
		}
	}

}
