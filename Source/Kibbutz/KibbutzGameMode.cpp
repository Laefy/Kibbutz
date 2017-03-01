// Fill out your copyright notice in the Description page of Project Settings.

#include "Kibbutz.h"
#include "KibbutzGameMode.h"
#include "Characters/MainCharacter.h"
#include "Player/MainController.h"

AKibbutzGameMode::AKibbutzGameMode() {
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Characters/MainCharacterBP"));
	if (PlayerPawnBPClass.Class != NULL) {
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PlayerControllerClass = AMainController::StaticClass();
	NPCStatementsMap = UDialogueManager::LoadDialogues();

}