#pragma once
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

private:
	double pMouseXpos;
	double pMouseYpos;
	double pXoffset;
	double pYoffset;
};

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