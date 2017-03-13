#include "Kibbutz.h"
#include "KibbutzLevelScriptActor.h"

void AKibbutzLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();

	/*this->DayNightManager = new TimeManager(GetWorld());

	if (this->wTime) {
		this->TimeWidget = CreateWidget<UUserWidget>(GetWorld(), this->wTime);
		if (this->TimeWidget)
		{
			this->TimeWidget->AddToViewport();
		}

	}*/
}

void AKibbutzLevelScriptActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	/*UTextBlock* w = (UTextBlock*)this->TimeWidget->GetWidgetFromName("TimeTextBlock");
	w->SetText(FText::FromString(*this->DayNightManager->GetTime()));
	
	this->DayNightManager->RotateSun(DeltaSeconds);
	
	if (this->DayNightManager->isPreviousFrameNight != this->DayNightManager->isNight) {
		this->DayNightManager->isPreviousFrameNight = this->DayNightManager->isNight;

		if (this->DayNightManager->isNight) {
			this->BecomeNight();
		}
		else {
			this->BecomeDay();
		}
		                  
	}

	// Update BP variable
	this->Day = this->DayNightManager->GetDay();*/
}

