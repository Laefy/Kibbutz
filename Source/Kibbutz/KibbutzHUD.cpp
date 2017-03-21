#include "Kibbutz.h"
#include "KibbutzHUD.h"

AKibbutzHUD::AKibbutzHUD()
{
	/** Load class from asset in Content Browser of the UserWidget we created (UGUserWidget) */
	static ConstructorHelpers::FClassFinder<UUserWidget> BlueprintClass(TEXT("Class'/Game/UI/UI_Time.UI_Time_C'"));
	if (BlueprintClass.Class)
	{
		TimeWidgetClass = BlueprintClass.Class;
	}
}

void AKibbutzHUD::BeginPlay()
{
	Super::BeginPlay();

	if (TimeWidgetClass)
	{
		TimeWidget = CreateWidget<UUserWidget>(GetWorld(), TimeWidgetClass);

		if (TimeWidget)
		{
			TimeWidget->AddToViewport();
		}
	}
}