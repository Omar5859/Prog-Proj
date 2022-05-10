#include "Output.h"
#include<cmath>

Output::Output()
{
	//Initialize user interface parameters

	UI.width = 970;
	//Set New Width (Ali)

	UI.height = 700;
	UI.wx = 15;
	UI.wy = 15;

	UI.AppMode = DESIGN;	//Design Mode is the default mode
	UI.AppMode = SIMULATION;

	UI.StBrWdth = 50;
	UI.TlBrWdth = 50;
	UI.MnItWdth = 80;

	UI.DrawClr = BLUE;
	UI.HiClr = YELLOW;
	UI.MsgClr = RED;

	UI.ASSGN_WDTH = 150;
	UI.ASSGN_HI = 50;
	UI.Statement_Width = 100;  //Omar
	UI.Statement_HI = 50;      //Omar
	UI.Connector_Width = 5;    //Arrow width   *Omar
	UI.Connector_HI = 10;      //Arrow height  *Omar
	UI.Start_Radius = UI.End_Radius = 50;     //Start and End radius       *Omar
	UI.Parallelogram_Width = 100;  //Input and Output read shape width     *Omar
	UI.Parallelogram_HI = 50;     //Input and Output read shape height    *Omar

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Programming Techniques Project");

	ClearToolBar();
	pWind->SetPen(CORNFLOWERBLUE, 2);
	CreateDesignToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput()
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y)
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar()
{
	pWind->DrawLine(0, UI.height - UI.StBrWdth, UI.width, UI.height - UI.StBrWdth);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the Design Menu
void Output::CreateDesignToolBar()
{
	UI.AppMode = DESIGN;	//Design Mode
	int i = 0;
	ClearToolBar();
	//fill the tool bar 
	//You can draw the tool bar icons in any way you want.

	//Adding icons for each statement needed (Ali).
	pWind->DrawImage("images\\Cut.jpg", first, 0);
	pWind->DrawImage("images\\Copy.jpg", second, 0);
	pWind->DrawImage("images\\Paste.jpg", third, 0);
	pWind->DrawImage("images\\Delete.jpg", fourth, 0);
	pWind->DrawImage("images\\Move.jpg", fifth, 0);
	pWind->DrawImage("images\\Edit.jpg", sixth, 0);
	pWind->DrawImage("images\\Save1.jpg", seventh, 0);
	pWind->DrawImage("images\\Load 1.jpg", eighth, 0);
	pWind->DrawImage("images\\Select.jpg", ninth, 0);
	pWind->DrawImage("images\\Comment.jpg", tenth, 0);
	pWind->DrawImage("images\\Exit1.jpg", eleventh, 0);

	pWind->DrawImage("images\\Start.jpg", twelvth, 54);
	pWind->DrawImage("images\\End.jpg", thirteenth, 54);
	pWind->DrawImage("images\\Variable=#.jpg", fourteenth, 54);
	pWind->DrawImage("images\\Variable.jpg", fifteenth, 54);
	pWind->DrawImage("images\\Variable =.jpg", sixteenth, 54);
	pWind->DrawImage("images\\Condition1.jpg", seventeenth, 54);
	pWind->DrawImage("images\\Read.jpg", eighteenth, 54);
	pWind->DrawImage("images\\Write.jpg", ninteenth, 54);
	pWind->DrawImage("images\\Arrow.jpg", twentyth, 54);
	pWind->DrawImage("images\\Undo.jpg", twentyone, 54);
	pWind->DrawImage("images\\Redo.jpg", twentytwo, 54);
	pWind->DrawImage("images\\Simulation.jpg", twentythree, 54);

	

	//Draw a line under the toolbar
	pWind->SetPen(CORNFLOWERBLUE, 4);
	pWind->DrawLine(0, UI.TlBrWdth, UI.width, UI.TlBrWdth);
	pWind->DrawLine(0, 0, UI.width, 0);
	pWind->DrawLine(0, UI.TlBrWdth+54, UI.width, UI.TlBrWdth+54);

	for (int i = 0; i < 970; i = i + 80)
	{
		pWind->DrawLine(i, 0, i, UI.TlBrWdth);
		pWind->DrawLine(i, 0, i, UI.TlBrWdth+54);
	}
	//for loop for the vertical lines in the design tool bar (Ali).
}

void Output::CreateSimulationToolBar()
	{
		UI.AppMode = SIMULATION;	//Simulation Mode
		///TODO: add code to create the simulation tool bar
		ClearToolBar();

		pWind->DrawImage("images\\Switch Back.jpg", first, 54);
		pWind->DrawImage("images\\Validation.jpg", second, 54);
		pWind->DrawImage("images\\Debug.jpg", third, 54);
		pWind->DrawImage("images\\Simulate.jpg", fourth, 54);
		pWind->DrawImage("images\\Generate a File.jpg", fifth, 54);

		int i = 0;
		pWind->SetPen(CORNFLOWERBLUE, 3);

		pWind->DrawLine(0, UI.TlBrWdth, UI.width, UI.TlBrWdth);

		/*for (int i = ; i < 1440; i = i + 80)
		{
			pWind->DrawLine(i, 0, i, UI.TlBrWdth);
		} */
	} 

//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StBrWdth, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width,UI.TlBrWdth+54 );
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea()
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.TlBrWdth+54, UI.width, UI.height - UI.StBrWdth);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgClr, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StBrWdth / 1.5), msg);
}

//======================================================================================//
//								Statements Drawing Functions								//
//======================================================================================//

//Draw assignment statement and write the "Text" on it
void Output::DrawAssign(Point Left, int width, int height, string Text, bool Selected)
{
		int s = Text.size() * 20;      //Where s is the size of the input text

		pWind->SetPen(BLACK, 2);
		pWind->DrawString(Left.x - s / 4, Left.y - 10, Text);

		if (s > width)
		{
			width = s;
		}

		if (Selected)	//if stat is selected, it should be highlighted
			pWind->SetPen(UI.HiClr, 3);	//use highlighting color
		else
			pWind->SetPen(UI.DrawClr, 3);	//use normal color

		//Draw the statement block rectangle
		pWind->DrawRectangle(Left.x - width / 2, Left.y - height / 2, Left.x + width / 2, Left.y + height / 2, FRAME);
	
}

void Output::DrawStartEnd(Point Left, int Radius, string text, bool selected)   //Function declaration     *Omar
{
	if (selected)
		pWind->SetPen(UI.HiClr, 3);
	else
		pWind->SetPen(UI.DrawClr, 3);

	pWind->DrawCircle(Left.x, Left.y, Radius);

	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x - 20, Left.y - 10, text);
}
void Output::DrawConditionalStat(Point Left, int width, int height, string text, bool selected)      //If statement Rhombus shape   *Omar
{

	int s = text.size() * 20;      //Where s is the size of the input text

	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x - s / 4, Left.y - 10, text);

	if (s > width)
	{
		width = s;
	}


	if (selected)
		pWind->SetPen(UI.HiClr, 3);
	else
		pWind->SetPen(UI.DrawClr, 3);

	pWind->DrawLine(Left.x - width / 2, Left.y, Left.x, Left.y + height / 2);
	pWind->DrawLine(Left.x - width / 2, Left.y, Left.x, Left.y - height / 2);
	pWind->DrawLine(Left.x + width / 2, Left.y, Left.x, Left.y + height / 2);
	pWind->DrawLine(Left.x + width / 2, Left.y, Left.x, Left.y - height / 2);

}

void Output::DrawInputOutput(Point Left, int width, int height, string text, bool selected)      //Input and Output parallelogram shape     *Omar
{
	int s = text.size() * 20;      //Where s is the size of the input text

	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x - s / 4, Left.y - 10, text);

	if (s > width)
	{
		width = s;
	}

	if (selected)
		pWind->SetPen(UI.HiClr, 3);
	else
		pWind->SetPen(UI.DrawClr, 3);

	pWind->DrawLine(Left.x - width / 4, Left.y - height / 2, Left.x + (3 * width) / 4, Left.y - height / 2);
	pWind->DrawLine(Left.x - width / 4, Left.y - height / 2, Left.x - (3 * width) / 4, Left.y + height / 2);
	pWind->DrawLine(Left.x + width / 4, Left.y + height / 2, Left.x - (3 * width) / 4, Left.y + height / 2);
	pWind->DrawLine(Left.x + width / 4, Left.y + height / 2, Left.x + (3 * width) / 4, Left.y - height / 2);
}

void Output::DrawConnector(Point Left, Point Right, int width, bool selected)       //Arrows    *Omar
{
	if (selected)
		pWind->SetPen(UI.HiClr, 3);
	else
		pWind->SetPen(UI.DrawClr, 3);

	if (abs(Left.x - Right.x) > 20 && Right.y - Left.y > 20)     //Line inclined hyt2asem 2 lines
	{
		pWind->DrawLine(Left.x, Left.y, Right.x, Left.y);
		pWind->DrawLine(Right.x, Right.y, Right.x, Left.y);
		pWind->DrawTriangle(Right.x, Right.y, Right.x + 5, Right.y - 5, Right.x - 5, Right.y - 5);
	}
	else if (Right.y - Left.y < 20 && Right.y - Left.y > 0 && Left.x - Right.x > 0)   // Line inclined hyb2a horizontal to the left
	{
		pWind->DrawLine(Left.x, Left.y, Right.x, Left.y);
		pWind->DrawTriangle(Right.x, Left.y, Right.x + 5, Left.y - 5, Right.x + 5, Left.y + 5);
	}
	else if (Right.y - Left.y < 20 && Right.y - Left.y > 0)   //Line inclined hyb2a horizontal to the right
	{
		pWind->DrawLine(Left.x, Left.y, Right.x, Left.y);
		pWind->DrawTriangle(Right.x, Left.y, Right.x - 5, Left.y - 5, Right.x - 5, Left.y + 5);
	}
	else if (abs(Left.x - Right.x) < 20 && Right.y - Left.y > 0)    //Lines inclined htb2a vertical
	{
		pWind->DrawLine(Left.x, Left.y, Left.x, Right.y);
		pWind->DrawTriangle(Left.x, Right.y, Left.x - 5, Right.y - 5, Left.x + 5, Right.y - 5);
	}
	else if (Left.y - Right.y > 0)   // Line mn taht l fo2
	{
		pWind->DrawLine(Left.x, Left.y, Left.x - 200, Left.y);
		pWind->DrawLine(Left.x - 200, Left.y, Left.x - 200, Right.y);
		pWind->DrawLine(Left.x - 200, Right.y, Right.x, Right.y);
		pWind->DrawTriangle(Right.x, Right.y, Right.x - 5, Right.y - 5, Right.x - 5, Right.y + 5);
	}

	pWind->SetPen(BLACK, 2);
}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}