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

	/*
	cout << "fov, yoffset: " << fov << ":" << yoffset << endl;

	//if (fov >= 1.0f && fov <= 90.0f) {
		fov -= yoffset;
	//}	

	if (fov <= 1.0f) {
		fov = 1.0f;
	}

	if (fov >= 90.0f) {
		fov = 90.0f;
	}
	*/
}
