// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ItemModel.generated.h"

UCLASS()
class KIBBUTZ_API AItemModel: public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItemModel();

	// Return the static mesh for all items from this model.
	UStaticMesh* GetStaticMesh() const;

	FVector GetScale() const;

	// Call NotifyModelUpdate if the mesh has changed.
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& Event) override;

private:
	UPROPERTY(Category = Item, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMesh* Mesh;

	UPROPERTY(Category = Item, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		FVector Scale;

	UPROPERTY(Category = Item, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		FString Name;

	UPROPERTY(Category = Item, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float SellPrice;
};

FORCEINLINE UStaticMesh* AItemModel::GetStaticMesh() const {
	return Mesh;
}

FORCEINLINE FVector AItemModel::GetScale() const {
	return Scale;
}