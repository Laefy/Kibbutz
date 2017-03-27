// Fill out your copyright notice in the Description page of Project Settings.

#include "Kibbutz.h"
#include "KibbutzGameMode.h"
#include "NonPlayerCharacter.h"
#include "Data/RawCsvData.h"
#include "Runtime/AssetRegistry/Public/AssetRegistryModule.h"

ANonPlayerCharacter::ANonPlayerCharacter() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CurrentStatement = 0;
}

void ANonPlayerCharacter::BeginPlay() {
	Super::BeginPlay();
	AllocateDialogueToNPC();
	CurrentStatement = 0;
}

void ANonPlayerCharacter::AllocateDialogueToNPC() {
	AKibbutzGameMode* const KibbutzGameMode = GetWorld()->GetAuthGameMode<AKibbutzGameMode>();

	if (KibbutzGameMode->NPCStatementsMap.Find(FriendlyName) != nullptr) {
		NPCStatements = *KibbutzGameMode->NPCStatementsMap.Find(FriendlyName);
	} else {
		UE_LOG(DebugLog, Warning, TEXT("Unable to find dialogue for character named %s."), &FriendlyName);
		NPCStatements.Empty();
	}

	for (int i = 0; i < NPCStatements.Num(); ++ i) {
		if (!NPCStatements[i].Variable.IsEmpty()) {
			Conditions.Emplace(NPCStatements[i].Variable, false);
		}
	}
}

bool ANonPlayerCharacter::HasStatement() {
	if (GetWorld() == nullptr) {
		return false;
	}

	AKibbutzGameMode* GameMode = GetWorld()->GetAuthGameMode<AKibbutzGameMode>();
	if (GameMode == nullptr) {
		return nullptr;
	}

	int Day = GameMode->Clock.days;
	for (int Next = CurrentStatement; Next < NPCStatements.Num(); ++ Next) {
		if (NPCStatements[Next].Day == Day) {
			FString const& Variable = NPCStatements[Next].Variable;
			if (Variable.IsEmpty() || Conditions[Variable]) {
				CurrentStatement = Next;
				return true;

			} else {
				//return false;
			}
		}
	}

	return false;
}

void ANonPlayerCharacter::MakeChoice(int Choice) {
	CurrentStatement = FMath::Max(0, NPCStatements[CurrentStatement].Player_Responses[Choice].Go_To_Statement - 1);
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

void ANonPlayerCharacter::SetCondition(FString Condition, bool State) {
	if (!Conditions.Contains(Condition)) {
		UE_LOG(DebugLog, Warning, TEXT("Unknown condition %s."), &Condition);
		return;
	}

	Conditions[Condition] = State;
}

void ANonPlayerCharacter::SkipStatement() {
	++ CurrentStatement;
}
