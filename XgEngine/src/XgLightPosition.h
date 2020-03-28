#pragma once
#include "XgLight.h"


class XgLightPosition :
	public XgLight
{
public:
	XgLightPosition(float x, float y, float z);
	virtual ~XgLightPosition();

public:
	void update(vec3 &position, vec3 &colour);

private:
	float x;
	float y;
	float z;
};

