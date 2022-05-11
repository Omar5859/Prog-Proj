#pragma once

#include "Actions/Action.h"
#include "Statements/Connector.h"

class AddConnector : public Action
{
	Point From;
	Point To;
public:
	AddConnector(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();
};