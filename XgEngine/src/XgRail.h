#pragma once

#include "Xg.h"

class XgRail
{
public:
	XgRail();
	virtual ~XgRail();

public:
	virtual void update(vec3 &position, vec3 &colour) = 0;
};

