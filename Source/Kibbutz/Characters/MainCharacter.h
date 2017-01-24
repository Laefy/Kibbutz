// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

/**
 * The main character, controlled by the player.
 */
UCLASS()
class KIBBUTZ_API AMainCharacter: public ACharacter {
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	// Override AActor::BeginPlay.
	virtual void BeginPlay() override;

	// Override AActor::Tick.
	virtual void Tick(float DeltaSeconds) override;

	// Move the character toward the given destination.
	void MoveTo(FVector const& destination);

private:
	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* SpringArm;
};
