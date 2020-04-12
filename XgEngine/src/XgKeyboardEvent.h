#pragma once

/*****************************************************************************
classs XgKeyboardEvent
*****************************************************************************/

class XgKeyboardEvent
{
public:
	XgKeyboardEvent();
	virtual ~XgKeyboardEvent();

public:
	void setMousePosition(double xpos, double ypos);
	void setScrollPosition(double xoffset, double yoffset);

	void zeroOffSet();

	double mouseXpos();
	double mouseYpos();

	double xOffset();
	double yOffSet();

	void setKey(int key, int scancode, int action, int mods);

private:
	double pMouseXpos;
	double pMouseYpos;
	double pXoffset;
	double pYoffset;

	int key;
	int scancode;
	int action;
	int mods;
};

inline void XgKeyboardEvent::setKey(int key, int scancode, int action, int mods)
{
	this->key = key;
	this->scancode = scancode;
	this->action = action;
	this->mods = mods;
}

/*****************************************************************************
getXpos()
*****************************************************************************/
inline double XgKeyboardEvent::mouseXpos()
{
	return(pMouseXpos);
}

/*****************************************************************************
getYpos()
*****************************************************************************/
inline double XgKeyboardEvent::mouseYpos()
{
	return(pMouseYpos);
}

inline double XgKeyboardEvent::xOffset()
{
	return(pXoffset);
}

inline double XgKeyboardEvent::yOffSet()
{
	return(pYoffset);
}

inline void XgKeyboardEvent::zeroOffSet()
{
	pXoffset = 0.0;
	pYoffset = 0.0;
}