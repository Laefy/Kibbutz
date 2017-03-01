// Fill out your copyright notice in the Description page of Project Settings.

#include "Kibbutz.h"
#include "ItemModel.h"
#include "Item.h"


AItemModel::AItemModel() {
	PrimaryActorTick.bCanEverTick = false;

	Mesh = nullptr;
	Scale = FVector(1.f, 1.f, 1.f);
	SellPrice = 0.f;
}

void AItemModel::PostEditChangeProperty(struct FPropertyChangedEvent& Event) {
	FName PropertyName = (Event.MemberProperty != nullptr) ? Event.MemberProperty->GetFName() : NAME_None;

	if (PropertyName == GET_MEMBER_NAME_CHECKED(AItemModel, Mesh) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(AItemModel, Scale)) {

		for (TActorIterator<AItem> ItemItr(GetWorld()); ItemItr; ++ ItemItr) {
			AItem* Item = *ItemItr;
			Item->NotifyModelUpdate(this);
		}
	}

	Super::PostEditChangeProperty(Event);
}