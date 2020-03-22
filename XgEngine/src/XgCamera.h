#pragma once

#include "Xg.h"
#include "XgTracker.h"
#include "XgCameraTelemetry.h"

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

private:
	XgCameraTelemetry telemetry;

	vector<XgTracker*> tracking;
};

