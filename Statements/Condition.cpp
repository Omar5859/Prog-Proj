#include "Condition.h"
#include <sstream>

using namespace std;

Condition::Condition(Point Center, string OP, string LeftHS, double RightHS, ApplicationManager* app):Statement(Center)
{
	LHS = LeftHS;
	Operation = OP;
	RHS = RightHS;

	UpdateStatementText();

	CenterPoint = Center;

	pConn = NULL;   //will be changed after connectors are done
	pApp = app;

	widthS = UI.Statement_Width;
	heightS = UI.Statement_HI;

	vStatX.first = CenterPoint.x - widthS / 2;
	vStatX.second = CenterPoint.x + widthS / 2;

	vStatY.first = CenterPoint.y - heightS / 2;
	vStatY.second = CenterPoint.y + heightS / 2;

	Inlet.x = CenterPoint.x;
	Inlet.y = CenterPoint.y - UI.Statement_HI / 2;
	OutletYes.x = CenterPoint.x + UI.Statement_Width / 2;  //Yes will point to the right
	OutletYes.y = CenterPoint.y;
	OutletNo.x = CenterPoint.x - UI.Statement_Width / 2;
	OutletNo.y = CenterPoint.y;
}

void Condition::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}

void Condition::setOperation(string& OP)
{
	Operation = OP;
	UpdateStatementText();
}

void Condition::setRHS(double R)
{
	RHS = R;
	UpdateStatementText();
}

void Condition::Draw(Output *pOut) const
{
	pOut->DrawConditionalStat(CenterPoint, UI.Statement_Width, UI.Statement_HI, Text, Selected);
}

void Condition::UpdateStatementText()
{
	if (LHS == "")	//No left handside ==>statement have no valid text yet
		Text = "if ";
	else
	{
		//Build the statement text: Left handside then equals then right handside
		ostringstream T;
		T << "if " << LHS << " " << Operation << " " << RHS;
		Text = T.str();
	}
}
