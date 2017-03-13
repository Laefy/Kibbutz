// Fill out your copyright notice in the Description page of Project Settings.

#include "Kibbutz.h"
#include "ClockStruct.h"

FClockStruct::FClockStruct()
{
}

FClockStruct::FClockStruct(int _days, int _hours, int _minutes)
{
	days = _days;
	hours = _hours;
	minutes = _minutes;
}

FClockStruct::~FClockStruct()
{
}
