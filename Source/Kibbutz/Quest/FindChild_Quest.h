// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Quest.h"
#include "FindChild_Quest.generated.h"

class UPrimitiveComponent;
struct FHitResult;

/**
* @brief A quest is an base object used to handle the advancement of the player in a given quest.
* Inherit it in order to use it.
*/
UCLASS()
class KIBBUTZ_API AFindChild_Quest: public AQuest {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFindChild_Quest();

	// Override Quest::AddedToBook.
	virtual void AddedToBook() override;

	// Overrides Quest::CheckStepCompleted.
	virtual bool CheckStepCompleted(int CurrentStep);

protected:
	// The woods area.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Find Child Quest", meta = (AllowPrivateAccess))
		AActor* WoodArea;

	// The child to find.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Find Child Quest", meta = (AllowPrivateAccess))
		AActor* Child;

private:
	TArray<bool> CompletedSteps;

	UFUNCTION()
	void OnWoodsReached(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void OnChildFound(UPrimitiveComponent* Comp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};
