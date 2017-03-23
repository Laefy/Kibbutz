// Fill out your copyright notice in the Description page of Project Settings.

#include "Kibbutz.h"
#include "Item.h"
#include "ItemModel.h"

// Sets default values
AItem::AItem() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Model = nullptr;

	Entity = CreateDefaultSubobject<USceneComponent>(TEXT("Entity"));
	RootComponent = Entity;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Entity);
}

void AItem::BeginPlay() {
	Super::BeginPlay();
}

void AItem::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AItem::PostLoad() {
	Super::PostLoad();
	Update();
}

#if WITH_EDITOR
void AItem::PostEditChangeProperty(struct FPropertyChangedEvent& Event) {
	FName PropertyName = (Event.Property != nullptr) ? Event.Property->GetFName() : NAME_None;
	if (PropertyName == GET_MEMBER_NAME_CHECKED(AItem, Model)) {
		Update();
	}

	Super::PostEditChangeProperty(Event);
}
#endif

void AItem::NotifyModelUpdate(AItemModel* ItemModel) {
	if (ItemModel == Model) {
		Update();
	}
}

void AItem::Update() {
	if (Model != nullptr) {
		Mesh->SetStaticMesh(Model->GetStaticMesh());
		Entity->SetWorldScale3D(Model->GetScale());
	}
}