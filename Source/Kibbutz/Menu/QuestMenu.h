// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "QuestMenu.generated.h"

class AQuestBook;

/**
 * The quest menu widget.
 */
UCLASS()
class KIBBUTZ_API UQuestMenu: public UUserWidget {
	GENERATED_BODY()

public:
	FORCEINLINE void SetQuestBook(AQuestBook* Book) {
		QuestBook = Book;
	}

	// Go to the next quest page.
	/*FORCEINLINE*/ UFUNCTION(BlueprintCallable, Category = "Quest")
	void NextPage() {
		++ Page;
	}

	// Go to the previous quest page.
	/*FORCEINLINE*/ UFUNCTION(BlueprintCallable, Category = "Quest")
	void PreviousPage() {
		-- Page;
	}

protected:
	// The quest book.
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
		AQuestBook* QuestBook = nullptr;

	// The current quest page.
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
		int Page = 0;
};
