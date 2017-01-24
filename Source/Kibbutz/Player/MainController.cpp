// Fill out your copyright notice in the Description page of Project Settings.

#include "Kibbutz.h"
#include "Player/MainController.h"
#include "Characters/MainCharacter.h"

AMainController::AMainController() {
	bShowMouseCursor = true;
}

void AMainController::BeginPlay() {
	Super::BeginPlay();
	bMovingTo = false;
}

void AMainController::Tick(float DeltaSeconds) {
	if (bMovingTo) {
		FHitResult hit;
		if (GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Pointer), false, hit)) {
			UE_LOG(DebugLog, Error, TEXT("ActorIIII: %s"), *GetPawn()->GetActorRotation().ToString());
			Cast<AMainCharacter>(GetPawn())->MoveTo(hit.Location);
			UE_LOG(DebugLog, Error, TEXT("ActorPPPP: %s"), *GetPawn()->GetActorRotation().ToString());
		}
	}
}

void AMainController::StartMoveTo() {
	if (GetPawn()) {
		bMovingTo = true;
	}
}

void AMainController::StopMoveTo() {
	bMovingTo = false;
}

void AMainController::Possess(APawn* aPawn) {
	if (Cast<AMainCharacter>(aPawn)) {
		Super::Possess(aPawn);
	}
}

void AMainController::UnPossess() {
	Super::UnPossess();
	bMovingTo = false;
}

void AMainController::SetupInputComponent() {
	Super::SetupInputComponent();

	InputComponent->BindAction("Move", IE_Pressed, this, &AMainController::StartMoveTo);
	InputComponent->BindAction("Move", IE_Released, this, &AMainController::StopMoveTo);
}

