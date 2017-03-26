#pragma once
#include "PlayerResponse.h"
#include "NPCStatement.generated.h"

USTRUCT(BlueprintType)
struct FNPCStatement
{
	GENERATED_USTRUCT_BODY()

public:

	FNPCStatement()
	{
	}

	FNPCStatement(int day, FText dialogue, TArray<FPlayerResponse> responses)
	{
		Day = day;
		NPC_dialogue = dialogue;
		Player_Responses = responses;
	}

	FNPCStatement(int day, FText dialogue, TArray<FPlayerResponse> responses, FString quest)
	{
		Day = day;
		NPC_dialogue = dialogue;
		Player_Responses = responses;
		Quest = quest;
	}

	FNPCStatement(int day, FText dialogue, TArray<FPlayerResponse> responses, FString quest, FString variable)
	{
		Day = day;
		NPC_dialogue = dialogue;
		Player_Responses = responses;
		Quest = quest;
		Variable = variable;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogue)
		FText NPC_dialogue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogue)
		TArray<FPlayerResponse> Player_Responses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogue)
		int32 Day;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogue)
		FString Variable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogue)
		FString Quest;
};