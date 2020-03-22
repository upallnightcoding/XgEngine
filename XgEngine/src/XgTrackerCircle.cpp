#include "XgTrackerCircle.h"

XgTrackerCircle::XgTrackerCircle()
{
	this->distance = 1.0;
	this->height = 0.0;
}

XgTrackerCircle::XgTrackerCircle(float distance)
{
	this->distance = distance;
	this->height = 0.0;
}

XgTrackerCircle::XgTrackerCircle(float distance, float height)
{
	this->distance = distance;
	this->height = height;
}

XgTrackerCircle::~XgTrackerCircle()
{
}

/*****************************************************************************
update() - This tracker update uses the GLFW timer to move the camer around
the origin at a given distance.  The camer is the distance is determined by
the <distance> parameter and the height of the camera is determined by the 
<height> parameters.
*****************************************************************************/
void XgTrackerCircle::update(XgRenderContext *context)
{
	// Capture the distance and timer
	//-------------------------------
	float radius = distance;
	double timer = glfwGetTime();

	// Calculate the X and Z position
	//-------------------------------
	float camX = (float)(sin(timer) * radius);
	float camZ = (float)(cos(timer) * radius);

	// Determine the eye position of the camera
	//-----------------------------------------
	//context->setCamera(camX, height, camZ);

	context->cameraTelemetry()->set(camX, height, camZ);
}
