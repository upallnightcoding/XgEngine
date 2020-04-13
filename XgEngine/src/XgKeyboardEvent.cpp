#include "XgKeyboardEvent.h"

#include "Xg.h"

XgKeyboardEvent *XgKeyboardEvent::instance = 0;

/*****************************************************************************
getInstance() -
*****************************************************************************/
XgKeyboardEvent *XgKeyboardEvent::getInstance()
{
	if (instance == 0) {
		instance = new XgKeyboardEvent();
	}

	return(instance);
}

/*****************************************************************************
setKey() -
*****************************************************************************/
void XgKeyboardEvent::setKey(int key, int scancode, int action, int mods)
{
	this->key = key;
	this->scancode = scancode;
	this->action = action;
	this->mods = mods;
}

/*****************************************************************************
getKey() -
*****************************************************************************/
void XgKeyboardEvent::getKey(int &key, int &scancode, int &action, int &mods)
{
	key = this->key;
	scancode = this->scancode;
	action = this->action;
	mods = this->mods;
}

bool XgKeyboardEvent::isKeyPressed(int targetKey)
{
	return((targetKey == key) && (action == GLFW_PRESS));
}

/*****************************************************************************
zeroOffSet() -
*****************************************************************************/
void XgKeyboardEvent::zeroOffSet()
{
	pXoffset = 0.0;
	pYoffset = 0.0;
}

/*****************************************************************************
setMousePosition() -
*****************************************************************************/
void XgKeyboardEvent::setMousePosition(double xpos, double ypos)
{
	this->pMouseXpos = xpos;
	this->pMouseYpos = ypos;
}

/*****************************************************************************
setScrollPosition() -
*****************************************************************************/
void XgKeyboardEvent::setScrollPosition(double xoffset, double yoffset)
{
	this->pXoffset = xoffset;
	this->pYoffset = yoffset;
}

/*****************************************************************************
getXpos()
*****************************************************************************/
double XgKeyboardEvent::mouseXpos()
{
	return(pMouseXpos);
}

/*****************************************************************************
mouseYpos()
*****************************************************************************/
double XgKeyboardEvent::mouseYpos()
{
	return(pMouseYpos);
}

/*****************************************************************************
xOffset()
*****************************************************************************/
double XgKeyboardEvent::xOffset()
{
	return(pXoffset);
}

/*****************************************************************************
yOffSet()
*****************************************************************************/
double XgKeyboardEvent::yOffSet()
{
	return(pYoffset);
}
