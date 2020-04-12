#pragma once

#include "Xg.h"
#include "XgTracker.h"
#include "XgCameraTelemetry.h"

/*****************************************************************************
class XgCamera
*****************************************************************************/

class XgCamera
{
public:
	XgCamera();
	virtual ~XgCamera();

public:
	mat4 getView();
	void update(XgRenderContext *context);
	void add(XgTracker *track);
	void create(GLFWwindow* window);

	vec3 getPosition();
	void setPosition(float x, float y, float z);
	void setPosition(float value);

private:
	XgCameraTelemetry telemetry;

	vector<XgTracker*> tracking;
};

/******************************************************************************
setPosition() - Sets the camera position
******************************************************************************/
inline void XgCamera::setPosition(float x, float y, float z)
{
	telemetry.set(x, y, z);
}

/******************************************************************************
setPosition() - Sets the camera position
******************************************************************************/
inline void XgCamera::setPosition(float value)
{
	telemetry.set(0.0, 0.0, value);
}