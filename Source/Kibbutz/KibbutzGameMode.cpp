// Fill out your copyright notice in the Description page of Project Settings.

#include "Kibbutz.h"
#include "KibbutzGameMode.h"
#include "Characters/MainCharacter.h"
#include "Player/MainController.h"

AKibbutzGameMode::AKibbutzGameMode() {
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Characters/MainCharacterBP"));
	if (PlayerPawnBPClass.Class != NULL) {
		DefaultPawnClass = PlayerPawnBPClass.Class;
	} else {
		UE_LOG(DebugLog, Error, TEXT("Unable to find DefaultPawnClass."));
	}

	PlayerControllerClass = AMainController::StaticClass();
}
