#pragma once

#include "Xg.h"
#include "XgTracker.h"

class XgCamera
{
public:
	XgCamera();
	virtual ~XgCamera();

public:
	mat4 getView();
	void update();
	void add(XgTracker *track);
	void create(GLFWwindow* window);

	vec3 getPosition();
	void setPosition(float x, float y, float z);

private:
	vec3 eye;
	vec3 center;
	vec3 up;

	vector<XgTracker*> tracking;
};

