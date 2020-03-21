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

	mat4 getPerspective(float fov);

private:
	int pWidth;
	int pHeight;
	float pNear;
	float pFar;
};

/*****************************************************************************
height() -
*****************************************************************************/
inline int XgScreenSize::height() {
	return(pHeight);
}

/*****************************************************************************
width() -
*****************************************************************************/
inline int XgScreenSize::width() 
{
	return(pWidth);
}

/*****************************************************************************
near() - Returns the "near" clipping of the perspective.
*****************************************************************************/
inline float XgScreenSize::near()
{
	return(pNear);
}

/*****************************************************************************
far() - Returns the "far" clipping of the perspective.
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
getPerspective() -
*****************************************************************************/
inline mat4 XgScreenSize::getPerspective(float fov)
{
	return(perspective(radians(fov), aspect(), pNear, pFar));
}

