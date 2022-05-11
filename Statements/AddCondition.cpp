#include "AddCondition.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include <sstream>

using namespace std;

AddCondition::AddCondition(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddCondition::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Conditional Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Conditional Statement: Click to add variable");

	LeftText = pIn->GetString(pOut);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Conditional Statement: Click to add operation");

	Operate = pIn->GetString(pOut);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Conditional Statement: Click to add comparison Value");

	RightValue = pIn->GetValue(pOut);
	pOut->ClearStatusBar();
}

void AddCondition::Execute()
{
	ReadActionParameters();

	Condition* pCond = new Condition(Position, Operate, LeftText, RightValue);

	pManager->AddStatement(pCond);
}