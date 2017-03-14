#include "Kibbutz.h"
#include "DialogueManager.h"
#include "Runtime/AssetRegistry/Public/AssetRegistryModule.h"

const FString UDialogueManager::CSV_PATH = "/Game/NPCDialogue/csv";

UDialogueManager::UDialogueManager(const FObjectInitializer& ObjectInitializer)	: Super(ObjectInitializer)
{
}

/**
* Load all CSV dialogues into one global hasmap accessible by all NPC blueprints
**/
TMap<FString, TArray<FNPCStatement>> UDialogueManager::LoadDialogues()
{
	TMap<FString, FString> CSVMap;
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(FName("AssetRegistry"));
	IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();

	// Need to do this if running in the editor with -game to make sure that the assets in the following path are available
	TArray<FString> PathsToScan;
	PathsToScan.Add(CSV_PATH);
	AssetRegistry.ScanPathsSynchronous(PathsToScan);

	TArray<FAssetData> CSVList;
	AssetRegistry.GetAssetsByPath(FName(*CSV_PATH), CSVList, false);
	TArray<UObject*> CSVFiles;
	EngineUtils::FindOrLoadAssetsByPath(CSV_PATH, CSVFiles, EngineUtils::ATL_Regular);

	TMap<FString, TArray<FNPCStatement>> NPCStatementsMap;
	// Loop through all CSV file (one for each character
	for (auto CSV : CSVFiles)
	{
		UDataTable* CSVObject = Cast<UDataTable>(CSV);
		if (CSVObject != nullptr) {
			NPCStatementsMap.Add(CSVObject->GetName(), UDialogueManager::computeDialoguesIntoNPCStatements(CSVObject));
		}
	}

	return NPCStatementsMap;
}

/**
* Convert raw CSV data to NPCStatement struct	
*/
TArray<FNPCStatement> UDialogueManager::computeDialoguesIntoNPCStatements(const UDataTable* RawCsvData)
{
	TArray<FNPCStatement> NPCStatements;
	if (RawCsvData) {
		
		for (auto it : RawCsvData->RowMap)
		{
			// it.Key has the key from first column of the CSV file
			// it.Value has a pointer to a struct of data. You can safely cast it to your actual type, e.g FMyStruct* data = (FMyStruct*)(it.Value);
			FRawCsvData* data = (FRawCsvData*)(it.Value);

			TArray<FPlayerResponse> responses;

			if (data->Answer1.ToString() != "") {
				FPlayerResponse answer1(data->Answer1, data->A1Goto);
				responses.Add(answer1);
			}

			if (data->Answer2.ToString() != "") {
				FPlayerResponse answer2(data->Answer2, data->A2Goto);
				responses.Add(answer2);
			}

			if (data->Answer3.ToString() != "") {
				FPlayerResponse answer3(data->Answer3, data->A3Goto);
				responses.Add(answer3);
			}

			FNPCStatement temp(data->Question, responses);
			NPCStatements.Add(temp);
		}
	}

	return NPCStatements;
}