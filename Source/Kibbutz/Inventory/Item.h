// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class KIBBUTZ_API AItem: public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItem();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	#if WITH_EDITOR
	// Update the item when the model is changed.
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& Event) override;
	#endif

	// Call update after loading an item.
	virtual void PostLoad() override;

	// Notify that the given model has been updated.
	void NotifyModelUpdate(class AItemModel* ItemModel);

private:
	UPROPERTY(Category = Item, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class AItemModel* Model;

	UPROPERTY(Category = Item, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* Entity;

	class UStaticMeshComponent* Mesh;

	// Update the object after a change has happened.
	void Update();
};
