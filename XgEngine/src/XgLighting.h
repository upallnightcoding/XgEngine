#pragma once

#include "Xg.h"

#include "XgRail.h"

class XgLighting
{
public:
	XgLighting();
	virtual ~XgLighting();

public:
	void add(XgRail *rail);
	void update();

	vec3 getColour();
	vec3 getPosition();

	void setPosition(float x, float y, float z);

private:
	vec3 position;
	vec3 colour;

	vector<XgRail*> rails;
};

