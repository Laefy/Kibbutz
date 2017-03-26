// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Quest.generated.h"

/**
 * @brief A quest is an base object used to handle the advancement of the player in a given quest.
 * Inherit it in order to use it.
 */
UCLASS()
class KIBBUTZ_API AQuest: public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AQuest();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called after the quest has been added to the quest book.
	virtual void AddedToBook();

	// Call this in order to check whether to advance in the quest.
	virtual bool CheckAdvancement();

	// Called to check whether the current step has been completed or not.
	virtual bool CheckStepCompleted(int CurrentStep);

	// Return the current step.
	/*FORCEINLINE*/ UFUNCTION(BlueprintCallable, Category = "Quest")
	int CurrentStep() const {
		return Advance;
	}

protected:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	FString Title;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	FString Description;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	TArray<FString> Steps;

private:
	int Advance;
	bool Completed;
};
