// Fill out your copyright notice in the Description page of Project Settings.

#include "Kibbutz.h"
#include "NonPlayerCharacter.h"
#include "../Data/RawCsvData.h"


// Sets default values
ANonPlayerCharacter::ANonPlayerCharacter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	LoadDialogue();
}

// Called when the game starts or when spawned
void ANonPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ANonPlayerCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ANonPlayerCharacter::LoadDialogue()
{
	// TODO Use NPC name

	
	UDataTable* RawCsvData;
	static ConstructorHelpers::FObjectFinder<UDataTable>Lena_BP(TEXT("DataTable'/Game/NPCDialogue/csv/Lena.Lena'"));
	RawCsvData = Lena_BP.Object;

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

	// For each row 
	// Add npc Statement
	// Add all answers
	// TODO Days !

		/*FString FileContent;
		//Read the csv file
		FFileHelper::LoadFileToString(FileContent, *csvDialogue);
		TArray<FString> problems = RawCsvData->CreateTableFromCSVString(FileContent);

		if (problems.Num() > 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d"), problems.Num());
			for (int32 ProbIdx = 0; ProbIdx < problems.Num(); ProbIdx++)
			{
				//Log the errors
			}
		}
		else
		{
			//Updated Successfully
			UE_LOG(LogTemp, Warning, TEXT("aaaaa"));
		}*/
	

	/*
	FFileHelper::LoadANSITextFileToStrings(*path, NULL, dialogues);

	FVector temp;

	for (int i = 1; i < dialogues.Num(); i++)
	{
		FString dialogue = dialogues[i];
		UE_LOG(LogTemp, Warning, TEXT("%s"), *dialogue);
		TArray<FString> stringArray = {};
		// Id, Day, Variable, Question, Answer1, Answer2, Answer3, AnswerEnd, A1Goto, A2Goto, A3Goto
		
		dialogue.ParseIntoArray(stringArray, TEXT(","), false);
		UE_LOG(LogTemp, Warning, TEXT("%d"), stringArray.Num());
		// Question 
			UE_LOG(LogTemp, Warning, TEXT("%s"), *stringArray[2]);
		
		// Answer1
		UE_LOG(LogTemp, Warning, TEXT("%s"), *stringArray[4]);
		// Answer2
		UE_LOG(LogTemp, Warning, TEXT("%s"), *stringArray[5]);
		// Answer3
		UE_LOG(LogTemp, Warning, TEXT("%s"), *stringArray[6]);
		// A1Goto
		UE_LOG(LogTemp, Warning, TEXT("%s"), *stringArray[8]);
		// A2Goto
		UE_LOG(LogTemp, Warning, TEXT("%s"), *stringArray[9]);
		// A3Goto
		UE_LOG(LogTemp, Warning, TEXT("%s"), *stringArray[10]);

		UE_LOG(LogTemp, Warning, TEXT("Your message"));
		temp.X = FCString::Atof(*stringArray[0]);
		temp.Y = FCString::Atof(*stringArray[1]);
		temp.Z = FCString::Atof(*stringArray[2]);



	}*/
}

