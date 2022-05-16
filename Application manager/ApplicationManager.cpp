#include "ApplicationManager.h"
#include "Actions\AddSmplAssign.h"
#include "AddCondition.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	StatCount = 0;
	ConnCount = 0;
	pSelectedStat = NULL;	//no Statement is selected yet
	pSelectedConn = NULL;   //Omar

	ArrX = new pair<int,int>[200];
	ArrY = new pair<int,int>[200];
	
	//ArrX[ArrXindex].first = vStatX.first;
	//ArrX[ArrXindex].second = vStatX.second;

	UI.AppMode = DESIGN;

	//Create an array of Statement & Connector pointers and set them to NULL		
	for (int i = 0; i < MaxCount; i++)
	{
		StatList[i] = NULL;
		ConnList[i] = NULL;
	}
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to ActionType, create the corresponding action object
	switch (ActType)
	{
	case ADD_SMPL_ASSIGN:
		pAct = new AddSmplAssign(this);
		break;

	case ADD_CONDITION:
		///create AddCondition Action here
		pAct = new AddCondition(this);
		break;

	case SELECT:
		///create Select Action here

		break;

	case EXIT:
		///create Exit Action here

		break;

	case STATUS:
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
	}
}


//==================================================================================//
//						Statements Management Functions								//
//==================================================================================//
//Add a statement to the list of statements
void ApplicationManager::AddStatement(Statement* pStat)
{
	for (int i = 0; i < StatCount; i++)
	{
		if ((pStat->getvStatX().first < ArrX[i].second && pStat->getvStatX().first > ArrX[i].first) || (pStat->getvStatX().second < ArrX[i].second && pStat->getvStatX().second > ArrX[i].first))
		{
			if ((pStat->getvStatY().first < ArrY[i].second && pStat->getvStatY().first > ArrY[i].first) || (pStat->getvStatY().second < ArrY[i].second && pStat->getvStatY().second > ArrY[i].first))
			{
				pOut->PrintMessage("Error! Overlapping statements");
				return;
			}
		}
	}
	if (StatCount < MaxCount)
	{
		ArrX[StatCount] = (pStat->getvStatX());
		ArrY[StatCount] = (pStat->getvStatY());
		StatList[StatCount++] = pStat; 
	}
	else
		pOut->PrintMessage("Error! Max number of statements is reached");
}

////////////////////////////////////////////////////////////////////////////////////
Statement* ApplicationManager::GetStatement(Point P) const
{
	//If this point P(x,y) belongs to a statement return a pointer to it.
	//otherwise, return NULL


	///Add your code here to search for a statement given a point P(x,y)	

	return NULL;
}
////////////////////////////////////////////////////////////////////////////////////
//Returns the selected statement
Statement* & ApplicationManager::GetSelectedStatement() 
{
	return pSelectedStat;
}

////////////////////////////////////////////////////////////////////////////////////
//Set the statement selected by the user
void ApplicationManager::SetSelectedStatement(Statement* pStat)
{
	pSelectedStat = pStat;
}

void ApplicationManager::AddConnector(Connector* pConn)
{
	if (ConnCount < MaxCount)
		ConnList[ConnCount++] = pConn;
	else
		pOut->PrintMessage("Error! Max number of Connectors is reached");
}

Connector* ApplicationManager::GetConnector(Point P) const
{
	//Mehtaga tafkeer hn get el point ezay enaha bt belong ll connector, zy el statement bzabt

	return NULL;
}

void ApplicationManager::SetSelectedConnector(Connector* pConn)
{
	pSelectedConn = pConn;
}

Connector* & ApplicationManager::GetSelectedConnector()
{
	return pSelectedConn;
}

int ApplicationManager::GetStatCount()
{
	return StatCount;
}

int ApplicationManager::GetConnCount()
{
	return ConnCount;
}

Statement** ApplicationManager::GetStatList()
{
	return StatList;
}

Connector** ApplicationManager::GetConnList()
{
	return ConnList;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	//Draw all statements
	for (int i = 0; i < StatCount; i++)
		StatList[i]->Draw(pOut);

	//Draw all connections
	for (int i = 0; i<ConnCount; i++)
		ConnList[i]->Draw(pOut);
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////


//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < StatCount; i++)
		delete StatList[i];
	for (int i = 0; i<StatCount; i++)
		delete ConnList[i];
	delete pIn;
	delete pOut;

}
