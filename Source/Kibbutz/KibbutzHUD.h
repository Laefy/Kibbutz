#pragma once

#include "GameFramework/HUD.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "KibbutzHUD.generated.h"

/**
*	Kibbutz HUD
*	Displaying the time widget (clock)
*/
UCLASS()
class KIBBUTZ_API AKibbutzHUD : public AHUD
{
	GENERATED_BODY()

public:
	AKibbutzHUD();

	virtual void BeginPlay() override;

private:
	TSubclassOf<class UUserWidget> TimeWidgetClass;
	class UUserWidget *TimeWidget;
};