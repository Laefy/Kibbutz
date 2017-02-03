// Fill out your copyright notice in the Description page of Project Settings.

#include "Kibbutz.h"
#include "Characters/MainCharacter.h"
#include "Inventory/Item.h"
#include "Kismet/KismetMathLibrary.h"

AMainCharacter::AMainCharacter() {
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->RelativeRotation = FRotator(-30.f, 0.f, 0.f);
	SpringArm->TargetArmLength = 1000.f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 1.3f;
	SpringArm->bUsePawnControlRotation = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	InteractionArea = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionArea"));
	InteractionArea->SetSphereRadius(200.f);
	InteractionArea->bGenerateOverlapEvents = true;
	InteractionArea->SetupAttachment(RootComponent);

	Target = nullptr;

	GetCapsuleComponent()->SetCapsuleHalfHeight(105.f);
	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void AMainCharacter::BeginPlay() {
	Super::BeginPlay();

	// Delegates cannot be initialized in constructor.
	InteractionArea->OnComponentBeginOverlap.AddDynamic(this, &AMainCharacter::OnEnterInteractionArea);
	InteractionArea->OnComponentEndOverlap.AddDynamic(this, &AMainCharacter::OnLeaveInteractionArea);
}

void AMainCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AMainCharacter::MoveTo(FVector const& Destination) {
	// Movement direction.
	FVector Direction = (Destination - GetActorLocation()).GetSafeNormal();
	AddMovementInput(Direction, 10);

	// Set the new orientation.
	FRotator NewOrientation = Direction.Rotation();
	NewOrientation.Pitch = 0;
	NewOrientation.Roll = 0;
	SetActorRotation(NewOrientation);

	// Reajust the spring arm position.
	SpringArm->SetWorldRotation(FRotator(-30.f, 0.f, 0.f));
}

void AMainCharacter::OnEnterInteractionArea(UPrimitiveComponent* Component, AActor* Other, UPrimitiveComponent* OtherComponent, int32, bool, const FHitResult&) {
	AItem* Item = Cast<AItem>(Other);
	if (Item != nullptr) {
		Target = Item;
		UE_LOG(DebugLog, Warning, TEXT("Item in"));
	}
}

void AMainCharacter::OnLeaveInteractionArea(UPrimitiveComponent* Component, AActor* Other, UPrimitiveComponent* OtherComponent, int32) {
	AItem* Item = Cast<AItem>(Other);
	if (Item != nullptr) {
		Target = nullptr;
		UE_LOG(DebugLog, Warning, TEXT("Item out"));
	}
}

void AMainCharacter::OnInteraction() {
	if (Target != nullptr) {
		Target->Destroy();
		Target = nullptr;
	}
}

