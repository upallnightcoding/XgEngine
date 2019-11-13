#pragma once

#include "Xg.h"

#include "XgTracker.h"
class XgTrackerPosition :
	public XgTracker
{
public:
	XgTrackerPosition(float x, float y, float z);
	virtual ~XgTrackerPosition();

public:
	virtual void update(vec3 &eye, vec3 &center, vec3 &up);

private:
	float x;
	float y;
	float z;
};

