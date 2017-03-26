// Fill out your copyright notice in the Description page of Project Settings.

#include "Kibbutz.h"
#include "QuestBook.h"
#include "Quest.h"
#include "RepairHouse_Quest.h"

AQuestBook::AQuestBook() {
	PrimaryActorTick.bCanEverTick = false;
}

void AQuestBook::BeginPlay() {
	Super::BeginPlay();
}

void AQuestBook::AddQuest(AQuest* Quest) {
	Quests.Add(Quest);
	Quest->AddedToBook();
}
