// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

class ATargetPoint;

/**
 * The main character, controlled by the player.
 */
UCLASS()
class KIBBUTZ_API AMainCharacter: public ACharacter {
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	// Set up the overlap events.
	virtual void PostInitializeComponents() override;

	// Override AActor::BeginPlay.
	virtual void BeginPlay() override;

	// Override AActor::Tick.
	virtual void Tick(float DeltaSeconds) override;

	// Move the character toward the given destination.
	void MoveTo(FVector const& Destination);

	// Trigger the next day.
	UFUNCTION(BlueprintCallable, Category = "Timeline")
	void GoHome();

	// Triggered when an object enters the interaction area.
	UFUNCTION()
	void OnEnterInteractionArea(UPrimitiveComponent* Component, AActor* Other, UPrimitiveComponent* OtherComponent, int32 ComponentIndex, bool bSweep, const FHitResult& SweepResult);

	// Triggered when an object leaves the interaction area.
	UFUNCTION()
	void OnLeaveInteractionArea(UPrimitiveComponent* Component, AActor* Other, UPrimitiveComponent* OtherComponent, int32 ComponentIndex);

	// Launch interaction.
	void OnInteraction();

private:
	UPROPERTY(Category = Camera, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;

	UPROPERTY(Category = Camera, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArm;

	UPROPERTY(Category = Interaction, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* InteractionArea;

	class AItem* Target;

	UPROPERTY(Category = Timeline, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class ATargetPoint* Home;
};
