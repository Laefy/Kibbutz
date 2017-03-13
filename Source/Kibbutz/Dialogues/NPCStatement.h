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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogue)
		FText NPC_dialogue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogue)
		TArray<FPlayerResponse> Player_Responses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogue)
		int Day;
};