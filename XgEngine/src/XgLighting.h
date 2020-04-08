#pragma once

#include "Xg.h"

#include "XgLight.h"

class XgLighting
{
public:
	XgLighting();
	virtual ~XgLighting();

public:
	void add(XgLight *rail);
	void update();

	vec3 colour();
	vec3 position();

	void setPosition(float x, float y, float z);

private:
	vec3 pPosition;
	vec3 pColour;

	vector<XgLight*> rails;
};

/*****************************************************************************
getColour() - Return the color of the light
*****************************************************************************/
inline vec3 XgLighting::colour()
{
	return(pColour);
}

/*****************************************************************************
getPosition() - Return the position of the light
*****************************************************************************/
inline vec3 XgLighting::position()
{
	return(pPosition);
}
