// Fill out your copyright notice in the Description page of Project Settings.

#include "Kibbutz.h"
#include "QuestBook.h"

QuestBook::QuestBook()
{

}

QuestBook::~QuestBook()
{
}

void QuestBook::signal(EventType evt, string name)
{
}

void QuestBook::initQuest(QuestTitle questName)
{
	switch (questName)
	{
		case RepairHouse:
			// Do Something
			break;

	}
}