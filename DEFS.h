#ifndef DEFS_H
#define DEFS_H

//This file contais some global constants and definitions to be used in the project.

enum ActionType //The actions supported (you can add more if needed)
{
	ADD_START_STAT, //Add start statement    Bahga
	ADD_END_STAT,    //Add end statement     Aly

	ADD_INPUT,     //Aly
	ADD_OUTPUT,    //Aly

	ADD_SMPL_ASSIGN,//Add simple assignment statement   Doneee
	ADD_VAR_ASSIGN,	//Add variable assignment statement   Bahga
	ADD_SO_ASSIGN,  //Add a single operator assignment    Bahga

	ADD_CONDITION, //Add a conditional statement (for if and while-loop statements)   Omar

	ADD_CONNECTOR, //Add a connector between two statements   Omar
	
	/*-------------------------------------------------------------------------------------------------*/

	EDIT_STAT,	//Edit a statement  BONUS

	SELECT,		//Select a statement, a connector

	UNDO,
	REDO,

	RESIZE,		//Resize a figure(s)

	CUT,   //BONUS
	COPY,  //BONUS
	PASTE, //BONUS
	DEL,		//Delete a figure(s)  BONUS

	MOVE,		//Move a figure(s)
	SAVE,		//Save the whole graph to a file
	LOAD,		//Load a graph from a file
	EXIT,		//Exit the application

	ADD_COMMENT,     //Allows user   BONUS

	STATUS,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar
	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to simulation mode

	VALIDATE,  //start validation of flowchart 
	SIMULATE,  //start simulation
	DEBUG,     //step by step simulation
	GENERATE_FILE //make a file of the code drawn 
};


enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};

enum SimMenueItem {
	ITM_DSN_MODE,   //Switch to Design mode
	ITM_VALID, //Enables user for validating their flowchart 
	ITM_DEBUG, //trace flow step by step 
	ITM_SIM,   //Enables simulation of flowchart 
	ITM_GENFILE, //generate a file 

	ITM_SIM_CNT
};

enum DsgnMenuItemRow1 //The items of the design menu in first row(you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you change the menu items order, change the order here too
	ITM_CUT,
	ITM_COPY,
	ITM_PASTE,
	ITM_DELETE,     //Delete a figure(s)
	ITM_MOVE,       //Move a figure(s)
	ITM_EDIT_STAT,  //edit a statement 
	ITM_SAVE,       //Save the whole graph to a file
	ITM_LOAD,       //Load a graph from a file
	ITM_SELECT,     //Select a statement, a connector
	ITM_COMMENT,    //enables user to add a comment to a statement
	ITM_EXIT,		//Exit
	ITM_DSN_CNT1
};

enum DsgnMenuItemRow2 { //The items of the design menu in second row

	ITM_START,      //start the flowchart           
	ITM_END,        //end the flowchart
	ITM_SMPL_ASSIGN,//simple assignment statement.  x=5;   
	ITM_VAR_ASSIGN, //variable assigned a variable. x=y;
	ITM_SO_ASSIGN, //Single Operators assignment statements. x=y+2; supports (*,/,+,-)
	ITM_CONDITION,		//conditional statement
	ITM_READ,       //Reads statement from keyboard/ input device
	ITM_WRITE,      //writes value/ message to screem/output device
	ITM_CONNECTOR,  //insert connector 
	ITM_UNDO,
	ITM_REDO,
	ITM_SIM_MODE,   //Switch to simulatiom mode

	//ITM_RESIZE,     //Resize a figure(s)                             


	ITM_DSN_CNT2		//no. of design menu items ==> This should be the last line in this enum

};


enum IconPlace
{
	first = 0,
	second = 80,
	third = 160,
	fourth = 240,
	fifth = 320,
	sixth = 400,
	seventh = 480,
	eighth = 560,
	ninth = 640,
	tenth = 720,
	eleventh = 800,
	twelvth = 0,
	thirteenth = 80,
	fourteenth = 160,
	fifteenth = 240,
	sixteenth = 320,
	seventeenth = 400,
	eighteenth = 480,
	ninteenth = 560,
	twentyth = 640,
	twentyone = 720,
	twentytwo = 800,
	twentythree = 880
};


#ifndef NULL
#define NULL 0
#endif

#endif
