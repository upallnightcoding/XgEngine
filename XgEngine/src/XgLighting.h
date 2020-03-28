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

	vec3 getColour();
	vec3 getPosition();

	void setPosition(float x, float y, float z);

private:
	vec3 position;
	vec3 colour;

	vector<XgLight*> rails;
};

