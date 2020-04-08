#pragma once

#include "Xg.h"

class XgPoint
{
public:
	XgPoint();
	virtual ~XgPoint();

private:
	vec3 point;
	vec2 texture;
};

