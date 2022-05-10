#include "AddSmplAssign.h"



#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddSmplAssign::AddSmplAssign(ApplicationManager *pAppManager):Action(pAppManager)
{}

void AddSmplAssign::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	
	pOut->PrintMessage("Simple Value Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();	

	pOut->PrintMessage("Simple Value Assignment Statement: Click to add text");

	LeftText = pIn->GetString(pOut);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Simple Value Assignment Statement: Click to add Value");

	RightValue = pIn->GetValue(pOut);
	pOut->ClearStatusBar();
}

void AddSmplAssign::Execute()
{
	ReadActionParameters();
		
	
	//Calculating left corner of assignement statement block
	/*Point Center;
	Center.x = Position.x - UI.ASSGN_WDTH/2;
	Center.y = Position.y ;*/
	
	SmplAssign *pAssign = new SmplAssign(Position, LeftText, RightValue);

	pManager->AddStatement(pAssign);
}

