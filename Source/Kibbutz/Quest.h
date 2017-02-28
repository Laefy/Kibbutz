// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <string>

using namespace std;

/**
 * 
 */
class KIBBUTZ_API Quest
{
private:
	string title;
	string description;
	string stepDetail;
	int currentStep;
	bool isClosed;

public:
	Quest();
	~Quest();
	virtual void signal(int step, string name);
};
