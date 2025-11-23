#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.width = 1540;
	UI.height = 800;
	UI.wx = 0;
	UI.wy =0;

	UI.AppMode = DESIGN;	//Design Mode is the default mode

	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 40;
	UI.MenuItemWidth = 60;
	UI.DrawingAreaWidth = 0.75 * UI.width;

	UI.DrawColor = BLUE;
	UI.HighlightColor = RED;
	UI.MsgColor = RED;

	UI.ASSGN_WDTH = 150;
	UI.ASSGN_HI = 50;

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Programming Techniques Project");
	
	pWind->SetPen(RED,3);

	CreateDesignToolBar();
	CreateStatusBar();
	ClearDrawArea();
	ClearOutputBar();
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
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Complete this function
void Output::CreateDesignToolBar() //Draws the Design Menu
{
	UI.AppMode = DESIGN;	//Design Mode


	string MenuItemImages[DSN_ITM_CNT];
	MenuItemImages[ITM_START] = "images\\start.jpg";
	MenuItemImages[ITM_VALUE_ASSIGN] = "images\\assign.jpg";
	MenuItemImages[ITM_DECLARE] = "images\\declare.jpg";
	MenuItemImages[ITM_COND] = "images\\condition.jpg";
	MenuItemImages[ITM_INPUTOUTPUT] = "images\\inputoutput.jpg";
	MenuItemImages[ITM_CONNECTOR] = "images\\connector.jpg";
	MenuItemImages[ITM_END] = "images\\end.jpg";
	MenuItemImages[ITM_SELECT] = "images\\select.jpg";
	MenuItemImages[ITM_EDIT] = "images\\edit.jpg";
	MenuItemImages[ITM_DELETE] = "images\\delete.jpg";
	MenuItemImages[ITM_COPY] = "images\\copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\paste.jpg";
	MenuItemImages[ITM_SWITCH_TO_SIM] = "images\\switchtosim.jpg";
	MenuItemImages[ITM_SAVE] = "images\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\load.jpg";
	MenuItemImages[ITM_EXIT] = "images\\exit.jpg";


	//Draw menu item one image at a time
	for (int i = 0; i < DSN_ITM_CNT-10; i++)
		pWind->DrawImage(MenuItemImages[i], i *65, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	int j = 1;
	for (int i = DSN_ITM_CNT - 4; i > DSN_ITM_CNT - 11; i--)
	{
		pWind->DrawImage(MenuItemImages[i], 1040 - 65 * j, 0, UI.MenuItemWidth, UI.ToolBarHeight);
		j++;
	}
	int k = 1;
	for (int i = DSN_ITM_CNT-1; i > DSN_ITM_CNT - 4; i--)
	{
		pWind->DrawImage(MenuItemImages[i], 1540 - 75 * k, 0, UI.MenuItemWidth, UI.ToolBarHeight);
		k++;
	}
	//Draw a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateSimulationToolBar() //Draws the Simulation Menu
{
	UI.AppMode = SIMULATION;	//Simulation Mode


	string SimMenuItemImages[SIM_ITM_CNT];
	SimMenuItemImages[ITM_VALIDATE] = "images\\validate.jpg";
	SimMenuItemImages[ITM_RUN] = "images\\run.jpg";
	SimMenuItemImages[ITM_SWITCH_TO_DESIGN] = "images\\switchtodesign.jpg";

	for (int i = 0; i < SIM_ITM_CNT; i++)
		pWind->DrawImage(SimMenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea()
{
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.DrawingAreaWidth, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearOutputBar()
{
	//Create output bar by drawing a filled rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(LIGHTBLUE);
	pWind->DrawRectangle(UI.DrawingAreaWidth, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int) (UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawString(const int iX, const int iY, const string Text)
{
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(iX, iY, Text);
}
//////////////////////////////////////////////////////////////////////////////////////////

//======================================================================================//
//								Statements Drawing Functions								//
//======================================================================================//

//Draw assignment statement and write the "Text" on it
void Output::DrawAssign(Point Left, int width, int height, string Text, bool Selected)
{
	if(Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor,3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor,3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);
		
	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x+width/4, Left.y + height/4, Text);
}

//TODO: Add similar functions for drawing all other statements.
//		e.g. DrawDeclareStat(.....), DrawCondtionalStat(......), DrawStart(......), DrawEnd(.......), ...etc
//		Decide the parameters that should be passed to each of them
	
//TODO: Add DrawConnector function

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
