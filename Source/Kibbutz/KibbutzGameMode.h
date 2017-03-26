// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "Dialogues/DialogueManager.h"
#include "Time/TimeManager.h"
#include "Time/ClockStruct.h"
#include "KibbutzGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameEventDelegate_OnBecomeDay, uint8, Day);

/**
* The game mode.
*/
UCLASS()
class KIBBUTZ_API AKibbutzGameMode : public AGameMode {
	GENERATED_BODY()

public:
	// Constructor.
	AKibbutzGameMode();

	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Time)
		FClockStruct Clock;

	TMap<FString, TArray<FNPCStatement>> NPCStatementsMap;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Day Events")
		FGameEventDelegate_OnBecomeDay OnBecomeDay;

	UFUNCTION(BlueprintCallable, Category = "Timeline")
	void SetTime(FClockStruct const& Time);

	UFUNCTION(BlueprintCallable, Category = "Timeline")
	void BlockTime(bool Block);

	UFUNCTION(BlueprintCallable, Category = "Timeline")
	bool IsTimeBlocked() const;

private:
	void UpdateClock();

	ATimeManager* DayNightManager;
};