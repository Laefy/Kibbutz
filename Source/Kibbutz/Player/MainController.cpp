// Fill out your copyright notice in the Description page of Project Settings.

#include "Kibbutz.h"
#include "Player/MainController.h"
#include "Characters/MainCharacter.h"
#include "Quest/QuestBook.h"
#include "Menu/QuestMenu.h"

AMainController::AMainController() {
	static ConstructorHelpers::FClassFinder<UQuestMenu> QuestMenuBPClass(TEXT("/Game/Menu/Quest/QuestMenuBP"));
	QuestMenuClass = QuestMenuBPClass.Class;

	bShowMouseCursor = true;
}

void AMainController::PostInitializeComponents() {
	Super::PostInitializeComponents();
}

void AMainController::BeginPlay() {
	Super::BeginPlay();

	QuestBook = GWorld->SpawnActor<AQuestBook>(AQuestBook::StaticClass());
	if (QuestMenuClass != NULL) {
		QuestMenu = CreateWidget<UQuestMenu>(this, QuestMenuClass);
		QuestMenu->SetQuestBook(QuestBook);
	} else {
		UE_LOG(DebugLog, Error, TEXT("Unable to find QuestMenu BP class."));
	}

	bMovingTo = false;
}

void AMainController::Tick(float DeltaSeconds) {
	if (bMovingTo) {
		FHitResult hit;
		if (GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Pointer), false, hit)) {
			Cast<AMainCharacter>(GetPawn())->MoveTo(hit.Location);
		}
	}
}

void AMainController::AddQuest(AQuest* Quest) {
	QuestBook->AddQuest(Quest);
}

void AMainController::StartMoveTo() {
	if (GetPawn()) {
		bMovingTo = true;
	}
}

void AMainController::StopMoveTo() {
	bMovingTo = false;
}

void AMainController::Possess(APawn* aPawn) {
	if (Cast<AMainCharacter>(aPawn)) {
		Super::Possess(aPawn);
	}
}

void AMainController::UnPossess() {
	Super::UnPossess();
	bMovingTo = false;
}

void AMainController::SetupInputComponent() {
	Super::SetupInputComponent();

	InputComponent->BindAction("Move", IE_Pressed, this, &AMainController::StartMoveTo);
	InputComponent->BindAction("Move", IE_Released, this, &AMainController::StopMoveTo);
	InputComponent->BindAction("Interact", IE_Released, this, &AMainController::Interact);
	InputComponent->BindAction("QuestMenu", IE_Released, this, &AMainController::TriggerQuestMenu);
}

void AMainController::Interact() {
	Cast<AMainCharacter>(GetPawn())->OnInteraction();
}

void AMainController::TriggerQuestMenu() {
	if (QuestMenu == nullptr) {
		UE_LOG(DebugLog, Error, TEXT("Cannot open Quest menu, as it was not created."));
		return;
	}

	if (QuestMenu->IsInViewport()) {
		QuestMenu->RemoveFromParent();

	} else if (!QuestBook->IsEmpty()) {
		QuestMenu->AddToViewport();
	}
}
