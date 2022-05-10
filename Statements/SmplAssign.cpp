#include "SmplAssign.h"
#include <sstream>

using namespace std;

SmplAssign::SmplAssign(Point Center, string LeftHS, double RightHS)
{
	LHS = LeftHS;
	RHS = RightHS;

	UpdateStatementText();

	CenterPoint = Center;
	
	pConn = NULL;	//No connectors yet

	Inlet.x = CenterPoint.x;                        //Omar
	Inlet.y = CenterPoint.y - UI.ASSGN_HI / 2;    

	Outlet.x = Inlet.x;
	Outlet.y = CenterPoint.y + UI.ASSGN_HI / 2;	
}

void SmplAssign::setLHS(const string &L)
{
	LHS = L;
	UpdateStatementText();
}

void SmplAssign::setRHS(double R)
{
	RHS = R;
	UpdateStatementText();
}


void SmplAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssign(CenterPoint, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
	
}


//This function should be called when LHS or RHS changes
void SmplAssign::UpdateStatementText()
{
	if(LHS=="")	//No left handside ==>statement have no valid text yet
		Text = "    = ";
	else
	{
		//Build the statement text: Left handside then equals then right handside
		ostringstream T;
		T<<LHS<<" = "<<RHS;	
		Text = T.str();	 
	}
}