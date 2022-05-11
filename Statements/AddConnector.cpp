#include "AddConnector.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

AddConnector::AddConnector(ApplicationManager* pAppManager):Action(pAppManager)
{}

void AddConnector::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Connector: Click to set the starting point of the connector");
	pOut->ClearStatusBar();

	pIn->GetPointClicked(From);

	pOut->PrintMessage("Connector: Click to set the ending point of the connector");
	pOut->ClearStatusBar();

	pIn->GetPointClicked(To);
}

void AddConnector::Execute()
{
	ReadActionParameters();

	Connector* pConn = new Connector()
}