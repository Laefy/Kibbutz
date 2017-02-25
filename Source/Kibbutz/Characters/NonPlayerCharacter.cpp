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
	// TODO Days
	// TODO Variables

	// Build CSV path using character name e.g /Game/NPCDialogue/csv/Lena.Lena
	FString characterName = ANonPlayerCharacter::GetName();
	FString path = "/Game/NPCDialogue/csv/" + characterName + "." + characterName;

	UDataTable* RawCsvData;
	ConstructorHelpers::FObjectFinder<UDataTable>CSV(*path);
	RawCsvData = CSV.Object;

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

}

