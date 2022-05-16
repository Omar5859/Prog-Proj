#ifndef STATEMENT_H
#define STATEMENT_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <utility>
#include "..\GUI\Input.h"

//Base class for all Statements
class Statement
{
protected:
	int ID;			//Each Statement has an ID
	string Text;	//Statement text (e.g.  "X = 5" OR "if(salary > 3000)" and so on )
	bool Selected;	//true if the statement is selected on the flowchart
	static int ID_counter; //ID counter for each statement created
	Input* pIn;

	int widthS;
	int heightS;

	Point CenterPoint;	//Center of the statement block.
	pair<int, int> vStatX;
	pair<int, int> vStatY;

	virtual void UpdateStatementText() = 0;	//is called when any part of the stat. is edited	

	/// Add more parameters if needed.

public:
	Statement(Point P);
	void SetSelected(bool s);
	bool IsSelected() const;

	void SetCenterPoint(Input* In);

	int GetID();

	pair<int, int> getvStatX();
	pair<int, int> getvStatY();

	virtual void Draw(Output* pOut) const  = 0 ;	//Draw the statement
	
	

	///TODO:The following functions should be supported by the Statement class
	///		It should then be overridden by each derived Statement
	///		Decide the parameters that you should pass to each function and its return type	


	//virtual void Save(ofstream &OutFile) = 0;	//Save the Statement parameters to a file
	//virtual void Load(ifstream &Infile) = 0;	//Load the Statement parameters from a file


	//virtual void Move() = 0;		//Move the Statement on the flowchart
	//virtual void Edit() = 0;		//Edit the Statement parameter

	//virtual void GenerateCode(ofstream &OutFile) = 0;	//write the statement code to a file
	//virtual void Simulate();	//Execute the statement in the simulation mode


	//virtual void PrintInfo(Output* pOut) = 0;	//print all Statement info on the status bar
	
	///TODO: Add more functions if needed
};

#endif
