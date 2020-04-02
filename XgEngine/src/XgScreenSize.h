#pragma once

#include "Xg.h"

/*****************************************************************************
class XgScreenSize
*****************************************************************************/
class XgScreenSize
{
public:
	XgScreenSize(int screenWidth, int screenHeight);
	virtual ~XgScreenSize();

public:
	int height();
	int width();

	float aspect();

	float near();
	float far();

	void updateFov(float delta);

	mat4 getPerspective();

	void viewPort();

private:
	int pWidth;
	int pHeight;
	float pNear;
	float pFar;
	float pFov;
};

inline void XgScreenSize::viewPort()
{
	glViewport(0, 0, pWidth, pHeight);
}

/*****************************************************************************
updateFov() - 
*****************************************************************************/
inline void XgScreenSize::updateFov(float delta)
{
	pFov += delta;

	if (pFov <= 1.0f) {
		pFov = 1.0f;
	}

	if (pFov >= 90.0f) {
		pFov = 90.0f;
	}
}

/*****************************************************************************
height() - Returns the height of the screen.
*****************************************************************************/
inline int XgScreenSize::height() {
	return(pHeight);
}

/*****************************************************************************
width() - Returns the width of the screen.
*****************************************************************************/
inline int XgScreenSize::width() 
{
	return(pWidth);
}

/*****************************************************************************
near() - Returns the near clipping of the perspective.
*****************************************************************************/
inline float XgScreenSize::near()
{
	return(pNear);
}

/*****************************************************************************
far() - Returns the far clipping of the perspective.
*****************************************************************************/
inline float XgScreenSize::far()
{
	return(pFar);
}

/*****************************************************************************
aspect() - Returns the calculated aspect ration of screen width over screen
height.  The aspect ratio can then be used in the creation of the perspective
matrix.
*****************************************************************************/
inline float XgScreenSize::aspect()
{
	return((float)width() / (float)height());
}

/*****************************************************************************
getPerspective() - Returns the perspective matrix of the screen.
*****************************************************************************/
inline mat4 XgScreenSize::getPerspective()
{
	return(perspective(radians(pFov), aspect(), pNear, pFar));
}

