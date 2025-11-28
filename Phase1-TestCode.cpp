
#include "HelperFn.h"
#include "GUI\Input.h"
#include "GUI\Output.h"


//This is a test code to test the Input and Output classes

int main()
{

	Point Pi;
	Point Pf;
	Point P;

	//Create Input and Output objects to test
	Output* pOut = new Output();
	Input* pIn = pOut->CreateInput();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 0:	Testing the helper functions
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST0: Testing the helper functions");
	pIn->GetPointClicked(Pi);	//Wait for any click

	////////////
	//TODO: Add code here to 
	// 1- Read a (string) from the user --> just call the already impemented Input::GetString(...) fn
	// 2- Pass this string to IsValue(...) helper function 
	// 3- Print a message indicating its output (whether it's a value or not)
	// 4- -- REPEAT the same previous 3 steps to test: IsVariable(...) helper function
	// 5- -- REPEAT the same first 3 steps to test: ValueORVariable(...) helper function
	////////////

	pOut->PrintMessage("IsValue test, Click anywhere to start the test");
	pIn->GetPointClicked(Pi);
	pOut->ClearStatusBar();

	if (IsValue(pIn->GetString(pOut)))
	{
		pOut->PrintMessage("This is a valid value");
		pIn->GetPointClicked(Pi);
	}
	else
	{
		pOut->PrintMessage("This is not a valid value");
		pIn->GetPointClicked(Pi);
	}

	pOut->PrintMessage("IsVariable test, Click anywhere to start the test");
	pIn->GetPointClicked(Pi);
	pOut->ClearStatusBar();

	if (IsVariable(pIn->GetString(pOut)))
	{
		pOut->PrintMessage("This is a valid variable name");
		pIn->GetPointClicked(Pi);
	}
	else
	{
		pOut->PrintMessage("This is not a valid variable name");
		pIn->GetPointClicked(Pi);
	}

	pOut->PrintMessage("ValueORVariable test, Click anywhere to start the test");
	pIn->GetPointClicked(Pi);
	pOut->ClearStatusBar();

	OpType type = ValueORVariable(pIn->GetString(pOut));

	if (type == VALUE_OP)
	{
		pOut->PrintMessage("This is a valid value");
		pIn->GetPointClicked(Pi);

	}
	else
		if (type == VARIABLE_OP)
		{
			pOut->PrintMessage("This is a valid variable name");
			pIn->GetPointClicked(Pi);
		}
		else
			if (type == INVALID_OP)
			{
				pOut->PrintMessage("This is not a valid value nor a variable name");
				pIn->GetPointClicked(Pi);
			}

	//Starting the input and output classes test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(Pi);	//Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	Create The FULL Tool bar, the drawing area, the output bar and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(Pi);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	Drawing all the Statements with all possible states:
	//			Normal, highlighted, empty, filled with code
	//			Also drawing connectors
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any statement in any status, Click anywhere to continue");
	pIn->GetPointClicked(Pi);	//Wait for any click

	/// 2.1- Assignment statement test
	//Drawing assignment statements in all posible states

	pOut->PrintMessage("Drawing Simple Assignment statements in ALL STATES, Click to continue");

	//Drawing (normal) (empty) assignment statement --> STATE 1
	Pi.x = 100;	Pi.y = 100;
	pOut->DrawAssign(Pi, UI.ASSGN_WDTH, UI.ASSGN_HI, " = ");

	//Drawing (highlighted) (empty) assignment statement --> STATE 2
	Pi.x = 300;	Pi.y = 100;
	pOut->DrawAssign(Pi, UI.ASSGN_WDTH, UI.ASSGN_HI, " = ", true);

	//Drawing a resized empty assignment statement
	Pi.x = 100;	Pi.y = 200;
	pOut->DrawAssign(Pi, 80, UI.ASSGN_HI, " = ");

	//Drawing edited (normal) (non-empty) assignment statement --> STATE 3
	Pi.x = 100;	Pi.y = 300;
	pOut->DrawAssign(Pi, UI.ASSGN_WDTH, UI.ASSGN_HI, "Salary = 3000");

	//Drawing (highlighted) (non-empty) assignment statement --> STATE 4
	Pi.x = 300;	Pi.y = 300;
	pOut->DrawAssign(Pi, UI.ASSGN_WDTH, UI.ASSGN_HI, "Salary = 3000", true);

	pIn->GetPointClicked(Pi);	//Wait for any click
	pOut->ClearDrawArea();

	///2.2- Variable assignment & single operator assignment
	pOut->PrintMessage("Drawing other Assignment statements in ALL STATES, Click to continue");

	//Note: for other type of assignment, you can use the same draw assignment function but passing a different text

	////////////
	//TODO: Add code to draw other types of assignment statements (Variable and Operator) here in ALL STATES
	////////////

	//Drawing (normal) (empty) assignment statement --> STATE 1
	Pi.x = 100;	Pi.y = 100;
	pOut->DrawAssign(Pi, UI.ASSGN_WDTH, UI.ASSGN_HI, " = x ");

	//Drawing (highlighted) (empty) assignment statement --> STATE 2
	Pi.x = 300;	Pi.y = 100;
	pOut->DrawAssign(Pi, UI.ASSGN_WDTH, UI.ASSGN_HI, " = x ", true);

	//Drawing a resized empty assignment statement
	Pi.x = 100;	Pi.y = 200;
	pOut->DrawAssign(Pi, 80, UI.ASSGN_HI, " = x ");

	//Drawing edited (normal) (non-empty) assignment statement --> STATE 3
	Pi.x = 100;	Pi.y = 300;
	pOut->DrawAssign(Pi, UI.ASSGN_WDTH, UI.ASSGN_HI, "Salary = x ");

	//Drawing (highlighted) (non-empty) assignment statement --> STATE 4
	Pi.x = 300;	Pi.y = 300;
	pOut->DrawAssign(Pi, UI.ASSGN_WDTH, UI.ASSGN_HI, "Salary = x ", true);

	pIn->GetPointClicked(Pi);	//Wait for any click
	pOut->ClearDrawArea();



	//Drawing (normal) (empty) assignment statement --> STATE 1
	Pi.x = 100;	Pi.y = 100;
	pOut->DrawAssign(Pi, UI.ASSGN_WDTH, UI.ASSGN_HI, " = x + 3 ");

	//Drawing (highlighted) (empty) assignment statement --> STATE 2
	Pi.x = 300;	Pi.y = 100;
	pOut->DrawAssign(Pi, UI.ASSGN_WDTH, UI.ASSGN_HI, " = x + 3 ", true);

	//Drawing a resized empty assignment statement
	Pi.x = 100;	Pi.y = 200;
	pOut->DrawAssign(Pi, 100, UI.ASSGN_HI, " = x + 3 ");

	//Drawing edited (normal) (non-empty) assignment statement --> STATE 3
	Pi.x = 100;	Pi.y = 300;
	pOut->DrawAssign(Pi, UI.ASSGN_WDTH, UI.ASSGN_HI, "Salary = x + 3");

	//Drawing (highlighted) (non-empty) assignment statement --> STATE 4
	Pi.x = 300;	Pi.y = 300;
	pOut->DrawAssign(Pi, UI.ASSGN_WDTH, UI.ASSGN_HI, "Salary = x + 3", true);

	pIn->GetPointClicked(Pi);	//Wait for any click
	pOut->ClearDrawArea();


	/// 2.3- Conditional statement test
	//Drawing Conditional statements in all posible states
	pOut->PrintMessage("Drawing Conditional Statement in ALL STATES, Click to continue");

	////////////
	//TODO: Add code to draw different (Conditional) statements here in ALL STATES
	////////////

	//Drawing (normal) (empty) conditional statement --> STATE 1
	Pi.x = 100;	Pi.y = 100;
	pOut->DrawCondition(Pi, UI.ASSGN_WDTH, UI.ASSGN_HI, " x = 3 ", false);

	//Drawing (highlighted) (empty) conditional statement --> STATE 2
	Pi.x = 300;	Pi.y = 100;
	pOut->DrawCondition(Pi, UI.ASSGN_WDTH, UI.ASSGN_HI, " x = 3 ", true);

	//Drawing a resized empty conditional statement
	Pi.x = 100;	Pi.y = 200;
	pOut->DrawCondition(Pi, 100, UI.ASSGN_HI, " x = 3 ", false);

	//Drawing edited (normal) (non-empty) conditional statement --> STATE 3
	Pi.x = 100;	Pi.y = 300;
	pOut->DrawCondition(Pi, UI.ASSGN_WDTH, UI.ASSGN_HI, " x = 3 ", false);

	//Drawing (highlighted) (non-empty) conditional statement --> STATE 4
	Pi.x = 300;	Pi.y = 300;
	pOut->DrawCondition(Pi, UI.ASSGN_WDTH, UI.ASSGN_HI, " x = 3 ", true);

	pIn->GetPointClicked(Pi);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.4- Read statement test
	//Drawing Read statements in all posible states
	pOut->PrintMessage("Drawing Read Statement in ALL STATES, Click to continue");

	////////////
	//TODO: Add code to draw different (Read) statements here in ALL STATES
	////////////

	Pi.x = 100;	Pi.y = 100;
	pOut->DrawRead(Pi, UI.READ_WDTH, UI.ASSGN_HI, " Read x ", false);

	//Drawing (highlighted) (empty) Read statement --> STATE 2
	Pi.x = 300;	Pi.y = 200;
	pOut->DrawRead(Pi, UI.READ_WDTH, UI.ASSGN_HI, " Read x ", true);

	//Drawing a resized empty Read statement
	Pi.x = 100;	Pi.y = 200;
	pOut->DrawRead(Pi, 150, UI.ASSGN_HI, " Read x ", false);

	//Drawing edited (normal) (non-empty) Read statement --> STATE 3
	Pi.x = 100;	Pi.y = 300;
	pOut->DrawRead(Pi, UI.READ_WDTH, UI.ASSGN_HI, " Read x ", false);

	//Drawing (highlighted) (non-empty) Read statement --> STATE 4
	Pi.x = 300;	Pi.y = 300;
	pOut->DrawRead(Pi, UI.READ_WDTH, UI.ASSGN_HI, " Read x ", true);

	pIn->GetPointClicked(Pi);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.5- Write statement test
	//Drawing Write statements in all posible states
	pOut->PrintMessage("Drawing Write Statement in ALL STATES, Click to continue");

	////////////
	//TODO: Add code to draw different (Write) statements here in ALL STATES
	////////////

	Pi.x = 100;	Pi.y = 100;
	pOut->DrawWrite(Pi, UI.READ_WDTH, UI.ASSGN_HI, " Print x ", false);

	//Drawing (highlighted) (empty) Write statement --> STATE 2
	Pi.x = 300;	Pi.y = 100;
	pOut->DrawWrite(Pi, UI.READ_WDTH, UI.ASSGN_HI, " Print x ", true);

	//Drawing a resized empty Write statement
	Pi.x = 100;	Pi.y = 200;
	pOut->DrawWrite(Pi, 150, UI.ASSGN_HI, " Print x ", false);

	//Drawing edited (normal) (non-empty) Write statement --> STATE 3
	Pi.x = 100;	Pi.y = 300;
	pOut->DrawWrite(Pi, UI.READ_WDTH, UI.ASSGN_HI, " Print x ", false);

	//Drawing (highlighted) (non-empty) Write statement --> STATE 4
	Pi.x = 300;	Pi.y = 300;
	pOut->DrawWrite(Pi, UI.READ_WDTH, UI.ASSGN_HI, " Print x ", true);

	pIn->GetPointClicked(Pi);	//Wait for any click
	pOut->ClearDrawArea();


	/// 2.6- Start & End statements test
	//Drawing Start & End statements in all posible states
	pOut->PrintMessage("Drawing Start & End Statements in ALL STATES, Click to continue");


	Pi.x = 100;	Pi.y = 100;
	pOut->DrawStart(Pi, UI.START_WDTH, UI.START_HI, " Start ", false);

	//Drawing (highlighted) (empty) Read statement --> STATE 2
	Pi.x = 300;	Pi.y = 100;
	pOut->DrawStart(Pi, UI.START_WDTH, UI.START_HI, " End ", true);

	//Drawing a resized empty Read statement
	Pi.x = 100;	Pi.y = 200;
	pOut->DrawStart(Pi, 200, UI.START_HI, " Start ", false);

	//Drawing edited (normal) (non-empty) Read statement --> STATE 3
	Pi.x = 100;	Pi.y = 300;
	pOut->DrawStart(Pi, UI.START_WDTH, UI.START_HI, " Start ", false);

	//Drawing (highlighted) (non-empty) Read statement --> STATE 4
	Pi.x = 300;	Pi.y = 300;
	pOut->DrawStart(Pi, UI.START_WDTH, UI.START_HI, " End ", true);

	pIn->GetPointClicked(Pi);	//Wait for any click
	pOut->ClearDrawArea();


	/// 2.7- Connector test
	//Drawing Connector in all posible states
	pOut->PrintMessage("Drawing Connector in Normal and Highlighted STATES, Click to continue");


	//Drawing normal connector
	Pi.x = 100;  Pi.y = 100;
	Pf.x = 100;  Pf.y = 200;
	pOut->DrawConnector(Pi, Pf, pOut->direction::DOWN,false);

	//Drawing highlighted connector
	Pi.x = 150;  Pi.y = 100;
	Pf.x = 150;  Pf.y = 200;
	pOut->DrawConnector(Pi, Pf, pOut->direction::DOWN,true);

	//Drawing more complex connector (with a horizontal then vertical segments)
	Pi.x = 100;	Pi.y = 250;
	Pf.x = 150;  Pf.y = 350;
	P.x = 150;    P.y = 250;
	
	pOut->DrawConnector(Pi, P, pOut->direction::NoDirection, false);
	pOut->DrawConnector(P, Pf, pOut->direction::DOWN, false);

	//Drawing more complex highlighted connector (with a horizontal then vertical segments)
	Pi.x = 200;	Pi.y = 250;
	Pf.x = 250;  Pf.y = 350;
	P.x = 250;    P.y = 250;

	pOut->DrawConnector(Pi, P, pOut->direction::NoDirection, true);
	pOut->DrawConnector(P, Pf, pOut->direction::DOWN, true);

	pIn->GetPointClicked(Pi);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.8- Draw String TEST
	//Drawing a String in a specific location
	pOut->PrintMessage("Drawing A String, Click to continue");
	pIn->GetPointClicked(Pi);
	pOut->ClearStatusBar();
	//Note: the function of this drawing is already implemented in Output class , you only need to call it

	////////////
	//TODO: Add code to: 
	// 1- Get a String from the user --> using the already-implemented Input::GetString(...) fn
	// 2- Draw that string in location (400, 200) --> using the already-implemented Output::DrawString(...) fn
	////////////

	pOut->DrawString(400, 200, pIn->GetString(pOut));

	pIn->GetPointClicked(Pi);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: Read strings and a value from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(Pi);	//Wait for any click

	pOut->PrintMessage("Testing Input ability to read strings, values, variables and operators");

	////////////
	//TODO: Add code here to 
	// 1- Read a (double value) from the user and print it
	// 2- Read a (variable name) from the user and print it
	// 3- Read an (arithmatic operator) from the user and print it
	// 4- Read a (comparison operator) from the user and print it
	////////////

	/////////////////->>>>>>>SAMIR
	pOut->PrintMessage("Input test, Click anywhere to start the test");
	pIn->GetPointClicked(Pi);

	pOut->PrintMessage("GetValue, Click anywhere to start the test");
	pIn->GetPointClicked(Pi);
	pOut->ClearStatusBar();
	pIn->GetValue(pOut);

	pOut->PrintMessage("GetVariable, Click anywhere to start the test");
	pIn->GetPointClicked(Pi);
	pOut->ClearStatusBar();
	pIn->GetVariable(pOut);

	pOut->PrintMessage("GetArithOperator, Click anywhere to start the test");
	pIn->GetPointClicked(Pi);
	pOut->ClearStatusBar();
	pIn->GetArithOperator(pOut);

	pOut->PrintMessage("GetCompOperator, Click anywhere to start the test");
	pIn->GetPointClicked(Pi);
	pOut->ClearStatusBar();
	pIn->GetCompOperator(pOut);
	/////////////////->>>>>>

	pIn->GetPointClicked(Pi);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;

	////////////
	//TODO:  You must add a case for EACH action in the following (switch case)
	////////////

	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case ADD_START:
			pOut->PrintMessage("Action: add a start statement , Click anywhere");
			break;

		case ADD_DECLARE_VARIABLE:
			pOut->PrintMessage("Action: add a variable declaration statement , Click anywhere");
			break;

		case ADD_VALUE_ASSIGN:
			pOut->PrintMessage("Action: add a value assignment statement , Click anywhere");
			break;

		case ADD_VAR_ASSIGN:
			pOut->PrintMessage("Action: add a variable assignment statement , Click anywhere");
			break;

		case ADD_OPER_ASSIGN:
			pOut->PrintMessage("Action: add an operator assignment statement , Click anywhere");
			break;

		case ADD_CONDITION:
			pOut->PrintMessage("Action: add a conditional statement , Click anywhere");
			break;

		case ADD_READ:
			pOut->PrintMessage("Action: add a read statement , Click anywhere");
			break;

		case ADD_WRITE:
			pOut->PrintMessage("Action: add a write statement , Click anywhere");
			break;

		case ADD_CONNECTOR:
			pOut->PrintMessage("Action: add a connector , Click anywhere");
			break;

		case ADD_END:
			pOut->PrintMessage("Action: add an end statement , Click anywhere");
			break;

		case SELECT:
			pOut->PrintMessage("Action: select an action, Click anywhere");
			break;

		case EDIT_STAT:
			pOut->PrintMessage("Action: edit a statement, Click anywhere");
			break;

		case DEL:
			pOut->PrintMessage("Action: delete a statement, Click anywhere");
			break;

		case COPY:
			pOut->PrintMessage("Action: copy a statement, Click anywhere");
			break;
			
		case CUT:
			pOut->PrintMessage("Action: cut a statement, Click anywhere");
			break;

		case PASTE:
			pOut->PrintMessage("Action: paste a statement, Click anywhere");
			break;

		case SAVE:
			pOut->PrintMessage("Action: save the whole graph to a file, Click anywhere");
			break;

		case LOAD:
			pOut->PrintMessage("Action: load a graph from a file, Click anywhere");
			break;

		case SWITCH_SIM_MODE:
			pOut->PrintMessage("Action: Switch to Simulation Mode, creating simualtion tool bar");
			pOut->CreateSimulationToolBar();
			break;

		case VALIDATE:
			pOut->PrintMessage("Action: validate the flowchart, Click anywhere");
			break;

		case RUN:
			pOut->PrintMessage("Action: run the flowchart, Click anywhere");
			break;

		case SWITCH_DSN_MODE:
			pOut->PrintMessage("Action: Switch to Design Mode, creating Design tool bar");
			pOut->ClearSimulationToolBar();
			pOut->CreateDesignToolBar();
			break;

		case SIM_TOOL:
			pOut->PrintMessage("Action: a click on the Simulation Tool Bar, Click anywhere");
			break;

		case DRAWING_AREA:
			pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
			break;

		case OUTPUT_AREA:
			pOut->PrintMessage("Action: a click on the Output Area, Click anywhere");
			break;

		case STATUS:
			pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
			break;

		case DSN_TOOL:
			pOut->PrintMessage("Action: a click on the Design Tool Bar, Click anywhere");
			break;

		case EXIT:
			break;
		}
	} while (ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(Pi);


	delete pIn;
	delete pOut;
	return 0;
}


