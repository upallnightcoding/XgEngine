#pragma once
#include "XgTracker.h"

#include "Xg.h"

class XgTrackerWalkAround :
	public XgTracker
{
public:
	XgTrackerWalkAround(float cameraSpeed);
	virtual ~XgTrackerWalkAround();

public:
	virtual void update(vec3 &eye, vec3 &center, vec3 &up);

private:
	void updateCameraFront();
	void updateFov();

private:
	vec3 cameraPos;
	vec3 cameraFront;
	vec3 cameraUp;

	float cameraSpeed;

	bool firstMouse;

	double lastX;
	double lastY;

	double yaw = -90.0f;	
	double pitch = 0.0f;
};

