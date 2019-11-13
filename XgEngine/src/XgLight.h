#pragma once

#include "Xg.h"

#include "XgRail.h"

class XgLight
{
public:
	XgLight();
	virtual ~XgLight();

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

