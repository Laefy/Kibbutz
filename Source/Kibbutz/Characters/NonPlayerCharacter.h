// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "../Dialogues/NPCStatement.h"
#include "../Dialogues/PlayerResponse.h"
#include "NonPlayerCharacter.generated.h"

UCLASS()
class KIBBUTZ_API ANonPlayerCharacter : public ACharacter
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANonPlayerCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Default)
	TArray<FNPCStatement> NPCStatements;


private:
	void LoadDialogue();
	
	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;
};
