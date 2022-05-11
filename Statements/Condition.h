#pragma once

#include "Statements/Statement.h"

class Condition : public Statement
{
	string LHS;
	string Operation;
	double RHS;

	Connector* pConn;

	Point Inlet;
	Point OutletYes;     //Point where connector leaves from if the condition is true
	Point OutletNo;      //Point where connector leaves from if the condition is false

	Point CenterPoint;

	virtual void UpdateStatementText();

public:
	Condition(Point Center, string OP, string LeftHS="", double RightHS = 0);

	void setLHS(const string& L);
	void setOperation(string& O);
	void setRHS(double R);

	virtual void Draw(Output* pOut) const;
};