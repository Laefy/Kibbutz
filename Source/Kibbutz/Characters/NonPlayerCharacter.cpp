// Fill out your copyright notice in the Description page of Project Settings.

#include "Kibbutz.h"
#include "KibbutzGameMode.h"
#include "NonPlayerCharacter.h"
#include "../Data/RawCsvData.h"
#include "Runtime/AssetRegistry/Public/AssetRegistryModule.h"


// Sets default values
ANonPlayerCharacter::ANonPlayerCharacter() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ANonPlayerCharacter::BeginPlay() {
	Super::BeginPlay();
	AllocateDialogueToNPC();
}

// Called every frame
void ANonPlayerCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void ANonPlayerCharacter::AllocateDialogueToNPC() {
	FriendlyName = convertIDNametoName(ANonPlayerCharacter::GetName());
	AKibbutzGameMode* const KibbutzGameMode = GetWorld()->GetAuthGameMode<AKibbutzGameMode>();

	if (KibbutzGameMode->NPCStatementsMap.Find(FriendlyName) != nullptr) {
		NPCStatements = *KibbutzGameMode->NPCStatementsMap.Find(FriendlyName);
	}
}

/**
*	Convert Unreal ID Name to the real name of the character, e.g Chelsea_50 --> Chelsea
**/
FString ANonPlayerCharacter::convertIDNametoName(FString IDName) {
	int32 underscoreIndex;
	FString name = IDName;
	name.FindChar(*("_"), underscoreIndex);

	if (underscoreIndex > 0) {
		int32 nbrOfCharToRemove = name.Len() - underscoreIndex;
		name = name.LeftChop(nbrOfCharToRemove);
	}

	return name;
}
