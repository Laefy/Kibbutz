// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "QuestBook.generated.h"

class AQuest;

/**
* @brief A quest is an base object used to handle the advancement of the player in a given quest.
* Inherit it in order to use it.
*/
UCLASS()
class KIBBUTZ_API AQuestBook: public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties.
	AQuestBook();

	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	// Add a new quest to the quest book.
	virtual void AddQuest(AQuest* Quest);

	// Return whether the quest book is empty or not.
	FORCEINLINE bool IsEmpty() const {
		return Quests.Num() == 0;
	}

private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	TArray<AQuest*> Quests;
};
