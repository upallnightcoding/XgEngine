#include "XgKeyboardEvent.h"

#include "Xg.h"

XgKeyboardEvent::XgKeyboardEvent()
{
	mouseXpos = 0.0;
	mouseYpos = 0.0;

	xoffset = 0.0;
	yoffset = 0.0;

	fov = 45.0;
}

XgKeyboardEvent::~XgKeyboardEvent()
{
}

/*****************************************************************************
setMousePosition()
*****************************************************************************/
void XgKeyboardEvent::setMousePosition(double xpos, double ypos)
{
	mouseXpos = xpos;
	mouseYpos = ypos;
}

void XgKeyboardEvent::setScrollPosition(double xoffset, double yoffset)
{
	this->xoffset = xoffset;
	this->yoffset = yoffset;

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
}

float XgKeyboardEvent::getFov()
{
	return((float) fov);
}

/*****************************************************************************
getXpos()
*****************************************************************************/
double XgKeyboardEvent::getXpos()
{
	return(mouseXpos);
}

/*****************************************************************************
getYpos()
*****************************************************************************/
double XgKeyboardEvent::getYpos()
{
	return(mouseYpos);
}

