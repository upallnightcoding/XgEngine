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
	virtual void update(XgRenderContext *context);

private:
	float x;
	float y;
	float z;
};

