#include "Input.h"
#include "Output.h"
#include<iostream>
using namespace std;

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(Point &P) const
{
	pWind->WaitMouseClick(P.x, P.y);	//Wait for mouse click
}


string Input::GetString(Output *pO) const 
{
	string Str;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Str;
		if(Key == 8 )	//BackSpace is pressed
			Str.resize(Str.size() -1 );			
		else    
			Str += Key;
		pO->PrintMessage(Str);
	}
	return Str;
}
int Input::GetKeyPressed(Output* pO) const {
	char Key;
	pWind->WaitKeyPress(Key);
	return Key;
}


double Input::GetValue(Output* pO) const	// Reads a double value from the user 
{
	///TODO: add code to read a double value from the user and assign it to D
	double D;
	string Str;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			Str = "";
		//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
		{
			D = stod(Str);
			return D;
		}
		if (Key == 8)	//BackSpace is pressed
			Str.resize(Str.size() - 1);
		else
			Str += Key;
		pO->PrintMessage(Str);
	}
	return D;
	//Read a double value from the user
}


//ActionType Input::GetUserAction() const
//{	
//	//This function reads the position where the user clicks to determine the desired action
//
//	int x,y;
//	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
//
//	if(UI.AppMode == DESIGN )	//application is in design mode
//	{
//		//[1] If user clicks on the Toolbar
//		if ( y >= 0 && y < UI.TlBrWdth)
//		{	//Check whick Menu item was clicked
//			if( x >= 0 && x < UI.MnItWdth  )
//				return ADD_SMPL_ASSIGN;
//			if( x >= UI.MnItWdth && x < 2* UI.MnItWdth  )		
//				return ADD_CONDITION;
//			if( x >= UI.MnItWdth && x < 3* UI.MnItWdth  )		
//				return EXIT;
//
//			return DSN_TOOL;	//a click on empty part of the tool bar
//		
//		}
//		
//		//[2] User clicks on the drawing area
//		if ( y >= UI.TlBrWdth && y < UI.height - UI.StBrWdth)
//		{
//			return SELECT;	//user want to select/unselect a statement in the flowchart
//		}
//		
//		//[3] User clicks on the status bar
//		return STATUS;
//	}
//	else	//Application is in Simulation mode
//	{
//		return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
//	}
//
//}
//

ActionType Input::GetUserAction() const
{
	//This function reads the position where the user clicks to determine the desired action

	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the first row of the Tool bar
		if (y >= 0 && y < UI.TlBrWdth)
		{
			//Check whick Menu item was clicked
			//This assumes that menu items are lined up horizontally
			int ClickedItem = (x / UI.MnItWdth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItem)
			{//ALLYY
			case ITM_CUT: return CUT;
			case ITM_COPY: return COPY; 
			case ITM_PASTE: return PASTE;
			case ITM_DELETE: return DEL; 
			case ITM_MOVE: return MOVE;
			case ITM_EDIT_STAT: return EDIT_STAT;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_SELECT: return SELECT;
			case ITM_COMMENT:return ADD_COMMENT;
			
			//case ITM_RESIZE: return RESIZE;
			
			case ITM_EXIT:return EXIT;

			default: return DSN_TOOL;
			}
			//Alyyyyy
		}
		//[2] If user clicks on the second row of the Tool bar
		if (y >= UI.TlBrWdth && y < UI.TlBrWdth+54) {
			//Check whick Menu item was clicked
			//This assumes that menu items are lined up horizontally
			int ClickedItem = (x / UI.MnItWdth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItem) {
			case ITM_START: return ADD_START_STAT;
			case ITM_END: return ADD_END_STAT;
			case ITM_SMPL_ASSIGN: return ADD_SMPL_ASSIGN;
			case ITM_VAR_ASSIGN: return ADD_VAR_ASSIGN;
			case ITM_SO_ASSIGN: return ADD_SO_ASSIGN;
			case ITM_CONDITION: return ADD_CONDITION;
			case ITM_READ: return ADD_INPUT;
			case ITM_WRITE: return ADD_OUTPUT; 
			case ITM_CONNECTOR: return ADD_CONNECTOR;
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;
			case ITM_SIM_MODE: return SIM_MODE;

			default: return DSN_TOOL;
			}
		}
		//[3] User clicks on the drawing area
		if (y >= UI.TlBrWdth+54 && y < UI.height - UI.StBrWdth)
		{
			return SELECT;	//user want to select/unselect a statement in the flowchart
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//Application is in Simulation mode
	{     
		//Check whick Menu item was clicked
			//This assumes that menu items are lined up horizontally
		int ClickedItem = (x / UI.MnItWdth);
		//Divide x coord of the point clicked by the menu item width (int division)
		//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
		switch (ClickedItem) {
		case ITM_VALID: return VALIDATE;
		case ITM_SIM: return SIMULATE; 
		case ITM_DEBUG: return DEBUG;
		case ITM_GENFILE: return GENERATE_FILE;
		case ITM_DSN_MODE: return DSN_MODE;
			return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
		}
	}

}
Input::~Input()
{
}
