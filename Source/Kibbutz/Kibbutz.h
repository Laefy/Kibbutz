// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"

DECLARE_LOG_CATEGORY_EXTERN(DebugLog, Log, All);

// Collision channel dedicated to element that can be pointed with the mouse cursor.
#define ECC_Pointer ECC_GameTraceChannel1

enum QuestTitle { RepairHouse, OtherQuest };
enum EventType { ObjectPut, ObjectGiven, LocationEnter, LocationLeave, DialogUpdated, Sunrise };