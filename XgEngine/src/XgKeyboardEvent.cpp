#include "XgKeyboardEvent.h"

#include "Xg.h"

XgKeyboardEvent::XgKeyboardEvent()
{
	pMouseXpos = 0.0;
	pMouseYpos = 0.0;

	pXoffset = 0.0;
	pYoffset = 0.0;
}

XgKeyboardEvent::~XgKeyboardEvent()
{
}

/*****************************************************************************
setMousePosition()
*****************************************************************************/
void XgKeyboardEvent::setMousePosition(double xpos, double ypos)
{
	this->pMouseXpos = xpos;
	this->pMouseYpos = ypos;
}

/*****************************************************************************
setScrollPosition()
*****************************************************************************/
void XgKeyboardEvent::setScrollPosition(double xoffset, double yoffset)
{
	this->pXoffset = xoffset;
	this->pYoffset = yoffset;
}
