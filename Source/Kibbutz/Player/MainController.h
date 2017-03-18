// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "MainController.generated.h"

class AQuestBook;
class AQuest;
class UQuestMenu;

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

	// Override AActor::PostInitializeComponents.
	virtual void PostInitializeComponents() override;

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

	// Add a new quest for the player.
	void AddQuest(AQuest* Quest);
	
protected:
	// Override APlayerController::SetupInputComponent.
	virtual void SetupInputComponent() override;

	// The quest book.
	AQuestBook* QuestBook;

private:
	bool bMovingTo;

	// The quest menu.
	TSubclassOf<UQuestMenu> QuestMenuClass;
	UQuestMenu* QuestMenu;

	// Open or close the quest menu.
	void TriggerQuestMenu();
};
