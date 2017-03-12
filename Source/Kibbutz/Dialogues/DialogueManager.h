#pragma once
#include "NPCStatement.h"
#include "PlayerResponse.h"
#include "../Data/RawCsvData.h"
#include "DialogueManager.generated.h"

/**
 * 
 */
UCLASS()
class UDialogueManager : public UObject
{
	GENERATED_UCLASS_BODY()

public :
	static const FString CSV_PATH;
	static TMap<FString, TArray<FNPCStatement>> LoadDialogues();
private:
	static TArray<FNPCStatement> computeDialoguesIntoNPCStatements(const UDataTable* RawCsvData);
};
