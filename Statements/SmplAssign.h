#ifndef SMPL_ASSIGN_H
#define SMPL_ASSIGN_H

#include "Statement.h"
#include "..\ApplicationManager.h"

//Simple Assignment statement class
//The simple assignment statement assigns a variable to a value
class SmplAssign : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	double RHS;	//Right Handside (Value)

	Connector* pConn;	//Simple Assignment Stat. has one Connector to next statement
	ApplicationManager* pApp;

	Point Inlet;	//A point where connections enters this statement 
	Point Outlet;	//A point a connection leaves this statement

	virtual void UpdateStatementText();

public:
	SmplAssign(Point Center, string LeftHS = "", double RightHS = 0, ApplicationManager* app = NULL);

	void setLHS(const string& L);
	void setRHS(double R);

	virtual void Draw(Output* pOut) const;

};

#endif
