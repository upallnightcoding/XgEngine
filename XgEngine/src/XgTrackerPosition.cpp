#include "XgTrackerPosition.h"



XgTrackerPosition::XgTrackerPosition(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}


XgTrackerPosition::~XgTrackerPosition()
{
}

void XgTrackerPosition::update(vec3 &eye, vec3 &center, vec3 &up)
{
	eye.x = x;
	eye.y = y;
	eye.z = z;
}
