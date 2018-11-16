#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_LINE,					//line item in menu
	ITM_RECT,					//Recangle item in menu
	ITM_TRIANGLE,				//Triangle item in menu
	ITM_ELIPSE,					//Elipse item in menu
	ITM_RHOMBUS,				//Rhombus item in menu
	ITM_BLACK,					//black item in menu
	ITM_WHITE,					//white item in menu
	ITM_RED,					//red item in menu
	ITM_BLUE,					//blue item in menu
	ITM_GREEN,					//green item in menu
	ITM_SELECT,					//select item in menu
	ITM_CHANGECOLORBYDRAWING,	//CHANGE COLOR BY DRAWING item in menu
	ITM_CHANGECOLORBYFILLING,	//CHANGE COLOR BY filling item in menu
	ITM_COPY,					//copy item in menu
	ITM_CUT,					//cut item in menu
	ITM_PASTE,					//paste item in menu
	ITM_DELETE,					//delete item in menu
	ITM_SAVEGRAPH,				//save graph item in menu
	ITM_SAVETYPE,				//save by type item in menu
	ITM_LOAD,					//load item in menu
	ITM_RESIZE,					//Resize item in menu
	ITM_UNMUTE,					//unmute voice
	ITM_MUTE,					//mute voice
	ITM_PLAYMODE,				//Playmode item in menu
	//TODO: Add more items names here

	ITM_EXIT,		//Exit item

	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_SELECTBYCOLOR,			//select item by color
	ITM_SELECTBYFIGURE,			//select item by figure
	ITM_DRAWMODE,				//switch to draw mode
	ITM_EXIT2,					//exit in playmode


	//TODO: Add more items names here

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed

}UI;	//create a global object UI

#endif