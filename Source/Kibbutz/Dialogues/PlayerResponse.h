#pragma once
#include "PlayerResponse.generated.h"

USTRUCT(BlueprintType)
struct FPlayerResponse
{
	GENERATED_USTRUCT_BODY()

public:

	FPlayerResponse()
	{

	}

	FPlayerResponse(FText response, int32 go)
	{
		Player_Response = response;
		Go_To_Statement = go;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogue)
		FText Player_Response;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogue)
		int32 Go_To_Statement;
};