// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "MainController.generated.h"

/**
 * The main controller for the game.
 * Send actions to the character, the environment, the GUI, and so on.
 */
UCLASS()
class KIBBUTZ_API AMainController: public APlayerController {
	GENERATED_BODY()

public:
	// Constructor.
	AMainController();

	// Start running AMainCharacter::MoveTo.
	void StartMoveTo();

	// Stop running AMainCharacter::MoveTo.
	void StopMoveTo();

	// Override AActor::BeginPlay.
	virtual void BeginPlay() override;

	// Override AActor::Tick.
	virtual void Tick(float DeltaSeconds) override;

	// Override APlayerController::Possess.
	virtual void Possess(APawn* aPawn) override;

	// Override APlayerController::UnPossess.
	virtual void UnPossess() override;

	// Launch the active interaction.
	void Interact();

protected:
	// Override APlayerController::SetupInputComponent.
	virtual void SetupInputComponent() override;

private:
	bool bMovingTo;
};
