#pragma once
#include "RawCsvData.generated.h"

USTRUCT(BlueprintType)
struct FRawCsvData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	FRawCsvData()
	{
	
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogue)
		int32 Day;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogue)
		FString Variable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogue)
		FText Question;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogue)
		FText Answer1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogue)
		FText Answer2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogue)
		FText Answer3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogue)
		int32 A1Goto;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogue)
		int32 A2Goto;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogue)
		int32 A3Goto;
};