// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Dialogues/NPCStatement.h"
#include "Dialogues/PlayerResponse.h"
#include "NonPlayerCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameEventDelegate_OnVariableSet, FString, Variable);


UCLASS()
class KIBBUTZ_API ANonPlayerCharacter: public ACharacter {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ANonPlayerCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogue)
		TArray<FNPCStatement> NPCStatements;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogue)
		FString FriendlyName;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "NPC Event")
		FGameEventDelegate_OnVariableSet OnVariableSet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC Event")
		TMap<FString, bool> Conditions;


	UFUNCTION(BlueprintCallable, Category = Dialogue)
	void SetCondition(FString Condition, bool State);

	UFUNCTION(BlueprintCallable, Category = Dialogue)
		bool HasStatement();

	UFUNCTION(BlueprintCallable, Category = Dialogue)
	FORCEINLINE FNPCStatement GetStatement() const;

protected:
	UFUNCTION(BlueprintCallable, Category = Dialogue)
		void MakeChoice(int Choice);

	UFUNCTION(BlueprintCallable, Category = Dialogue)
		void SkipStatement();

private:
	void AllocateDialogueToNPC();
	FString convertIDNametoName(FString IDName);

	int CurrentStatement;
};

FORCEINLINE FNPCStatement ANonPlayerCharacter::GetStatement() const {
	return NPCStatements[CurrentStatement];
}