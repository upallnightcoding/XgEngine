#pragma once

#include "Xg.h"

class XgLight
{
public:
	XgLight();
	virtual ~XgLight();

public:
	virtual void update(vec3 &position, vec3 &colour) = 0;
};

