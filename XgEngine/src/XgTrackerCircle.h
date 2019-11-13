#pragma once
#include "XgTracker.h"
class XgTrackerCircle :
	public XgTracker
{
public:
	XgTrackerCircle();
	XgTrackerCircle(float distance);
	XgTrackerCircle(float distance, float height);
	virtual ~XgTrackerCircle();

public:
	void setDistance(float distance);
	void setHeight(float height);

public:
	virtual void update(vec3 &eye, vec3 &center, vec3 &up);

private:
	float distance;
	float height;
};

inline void XgTrackerCircle::setDistance(float distance)
{
	this->distance = distance;
}

inline void XgTrackerCircle::setHeight(float height)
{
	this->height = height;
}

