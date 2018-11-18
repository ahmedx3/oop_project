#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1500;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 60;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar() const
{
	//Clear tool bar by drawing a filled white rectangle
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\Menu_Line.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\Menu_Triangle.jpg";
	MenuItemImages[ITM_ELIPSE] = "images\\MenuItems\\Menu_Elipse.jpg";
	MenuItemImages[ITM_RHOMBUS] = "images\\MenuItems\\Menu_Rhombus.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\Menu_Black.jpg";
	MenuItemImages[ITM_WHITE] = "images\\MenuItems\\Menu_White.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Menu_Red.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Menu_Blue.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Menu_Green.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_CHANGECOLORBYDRAWING] = "images\\MenuItems\\Menu_Changebydrawing.jpg";
	MenuItemImages[ITM_CHANGECOLORBYFILLING] = "images\\MenuItems\\Menu_Changebyfilling.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\Menu_Copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Menu_Cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Menu_Paste.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_SAVEGRAPH] = "images\\MenuItems\\Menu_Savegraph.jpg";
	MenuItemImages[ITM_SAVETYPE] = "images\\MenuItems\\Menu_Savetype.jpg";
	MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\Menu_Resize.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";
	MenuItemImages[ITM_PLAYMODE] = "images\\MenuItems\\Menu_Playmode.jpg";
	MenuItemImages[ITM_UNMUTE] = "images\\MenuItems\\Menu_Unmute.jpg";
	MenuItemImages[ITM_MUTE] = "images\\MenuItems\\Menu_Mute.jpg";

	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	ClearToolBar();
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string PlayItemImages[PLAY_ITM_COUNT];
	PlayItemImages[ITM_SELECTBYCOLOR] = "images\\MenuItems\\Menu_Selectbycolor.jpg";
	PlayItemImages[ITM_SELECTBYFIGURE] = "images\\MenuItems\\Menu_Selectbyfigure.jpg";
	PlayItemImages[ITM_DRAWMODE] = "images\\MenuItems\\Menu_Drawmode.jpg";
	PlayItemImages[ITM_EXIT2] = "images\\MenuItems\\Menu_Exit.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(PlayItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//check for point 

bool Output::isChecked(Point p) const {
	int y = p.y;
	if (y > 50) {
		return true;
	}
	else {
		return false;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawRect(Point &P1, Point &P2, GfxInfo RectGfxInfo, bool selected) const
{
	
	int x, y;
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;
	if (selected == true) {
		pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	}
	else {
		if (isChecked(P1) && isChecked(P2)) {
			pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
		}
		else {

			PrintMessage(" click on specified area for drawing , click anywhere to continue ");
			Input *pIn = CreateInput();
			pIn->GetPointClicked(x, y);
			PrintMessage("Drawing a Rectangle   Click two points");
			pIn->GetPointClicked(P1.x, P1.y);
			pIn->GetPointClicked(P2.x, P2.y);
			DrawRect(P1,P2, RectGfxInfo, false);
		}


	}
	
		

	
	

}
void Output:: DRAWTri(Point &P1, Point &P2, Point &p3, GfxInfo RectGfxInfo, bool selected) const{
	int x, y;
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	if (selected == true) {
		pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, p3.x, p3.y, style);
	}
	else {
		if (isChecked(P1) && isChecked(P2) && isChecked(p3)) {
			pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, p3.x, p3.y, style);
		}
		else {
			PrintMessage(" click on specified area for drawing , click anywhere to continue ");
			Input *pIn = CreateInput();
			pIn->GetPointClicked(x, y);
			PrintMessage("Drawing a triangle   Click three points");
			pIn->GetPointClicked(P1.x, P1.y);
			pIn->GetPointClicked(P2.x, P2.y);
			pIn->GetPointClicked(p3.x, p3.y);
			DRAWTri(P1, P2, p3, RectGfxInfo, false);

		}
	}
	
}
void Output:: Drawelipse(Point &P1, GfxInfo RectGfxInfo, bool selected) const {
	int x, y;
color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;
	if (selected == true) {
		pWind->DrawCircle(P1.x, P1.y, 100, style);
	}
	else {


		if (isChecked(P1) && P1.y > 100) {
			pWind->DrawCircle(P1.x, P1.y, 100, style);
		}
		else {
			PrintMessage(" click on specified area for drawing and leave enough space from toolbar , click anywhere to continue ");
			Input *pIn = CreateInput();
			pIn->GetPointClicked(x, y);
			PrintMessage("Drawing an Eclipse   Click one points");
			pIn->GetPointClicked(P1.x, P1.y);
			Drawelipse(P1, RectGfxInfo, false);

		}
	}
}
void Output:: Draw_poly(Point &P1, GfxInfo RectGfxInfo, bool selected) const {
	int x, y;
int  *xp = new int  [4]; 
int  *yp = new int  [4]; 
yp[0] = P1.y +100; 
xp[0] = P1.x; 
yp[1] = P1.y; 
xp[1] = P1.x+50 ; 
xp[2] = P1.x ; 
yp[2] = P1.y-100 ;
xp[3] = P1.x -50; 
yp[3] = P1.y ;
color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;
	if (selected == true) {
		pWind->DrawPolygon(xp, yp, 4, style);
	}
	else {


		if (isChecked(P1) && yp[2] > 50 ) {
			pWind->DrawPolygon(xp, yp, 4, style);
		}
		else {
			PrintMessage(" click on specified area for drawing a rohmbus and leave enough space from toolbar  , click anywhere to continue ");
			Input *pIn = CreateInput();
			pIn->GetPointClicked(x, y);
			PrintMessage("Drawing a rohmbus   Click one point");
			pIn->GetPointClicked(P1.x, P1.y);
			Draw_poly(P1, RectGfxInfo, false);

		}
	}
	
}
	
void Output::DrawLine(Point &P1, Point &P2, GfxInfo RectGfxInfo, bool selected) const
{
	int x, y;
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	if (selected == true) {
		pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);
	}
	else {


		if (isChecked(P1) && isChecked(P2)) {
			pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);
		}
		else {
			PrintMessage(" click on specified area for drawing , click anywhere to continue ");
			Input *pIn = CreateInput();
			pIn->GetPointClicked(x, y);
			PrintMessage("Drawing a Line   Click two points");
			pIn->GetPointClicked(P1.x, P1.y);
			pIn->GetPointClicked(P2.x, P2.y);
			DrawLine(P1, P2, RectGfxInfo, false);

		}

	}
}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

