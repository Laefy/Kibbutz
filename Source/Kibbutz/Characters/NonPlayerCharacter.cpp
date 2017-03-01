// Fill out your copyright notice in the Description page of Project Settings.

#include "Kibbutz.h"
#include "KibbutzGameMode.h"
#include "NonPlayerCharacter.h"
#include "../Data/RawCsvData.h"
#include "Runtime/AssetRegistry/Public/AssetRegistryModule.h"


// Sets default values
ANonPlayerCharacter::ANonPlayerCharacter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ANonPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	AllocateDialogueToNPC();
}

// Called every frame
void ANonPlayerCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void ANonPlayerCharacter::AllocateDialogueToNPC()
{
	// TODO Days
	// TODO Variables
	FString characterName = ANonPlayerCharacter::GetName();

	AKibbutzGameMode* const KibbutzGameMode = GetWorld()->GetAuthGameMode<AKibbutzGameMode>();
	NPCStatements = *KibbutzGameMode->NPCStatementsMap.Find(characterName);
}

