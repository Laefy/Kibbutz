// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Quest.h"
#include "RepairHouse_Quest.generated.h"

class UPrimitiveComponent;
struct FHitResult;

/**
* @brief A quest is an base object used to handle the advancement of the player in a given quest.
* Inherit it in order to use it.
*/
UCLASS()
class KIBBUTZ_API ARepairHouse_Quest: public AQuest {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARepairHouse_Quest();

	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	// Overrides Quest::CheckStepCompleted.
	virtual bool CheckStepCompleted(int CurrentStep);

protected:
	// The hero house area.
	UPROPERTY(EditAnywhere, Category="Repair House Quest", meta=(AllowPrivateAccess))
	AActor* HeroHouseArea;

	// The woodcutter house area.
	UPROPERTY(EditAnywhere, Category = "Repair House Quest", meta = (AllowPrivateAccess))
	AActor* WoodcutterHouseArea;

private:
	TArray<bool> CompletedSteps;

	UFUNCTION()
	void OnWoodcutterHouseAreaBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void OnHeroHouseAreaBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
};
