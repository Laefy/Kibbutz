// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Quest.h"

/**
 * 
 */
class KIBBUTZ_API QuestBook
{
private:
	TArray<Quest> questList;

public:
	QuestBook();
	~QuestBook(); 
	void signal(int step, string name);
};
