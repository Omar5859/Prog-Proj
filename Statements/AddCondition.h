#pragma once

#include "Actions/\Action.h"
#include "Condition.h"

class AddCondition : public Action
{
	Point Position;
	string LeftText;
	string Operate;
	double RightValue;
public:
	AddCondition(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();
};