#pragma once

//#include "TimeManager.h"
 #include "Runtime/UMG/Public/UMG.h"
 #include "Runtime/UMG/Public/UMGStyle.h"
 #include "Runtime/UMG/Public/Slate/SObjectWidget.h"
 #include "Runtime/UMG/Public/IUMGModule.h"
 #include "Runtime/UMG/Public/Blueprint/UserWidget.h"

#include "Engine/LevelScriptActor.h"
#include "KibbutzLevelScriptActor.generated.h"


/**
 * Level Blueprint
 */
UCLASS()
class KIBBUTZ_API AKibbutzLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintImplementableEvent)
	void BecomeDay();

	UFUNCTION(BlueprintImplementableEvent)
	void BecomeNight();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> wTime;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	int Day;
private:
	//TimeManager* DayNightManager;
	//UUserWidget* TimeWidget;
	
};
