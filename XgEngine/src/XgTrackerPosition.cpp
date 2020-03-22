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

void XgTrackerPosition::update(XgRenderContext *context)
{
	context->cameraTelemetry()->set(x, y, z);
}
