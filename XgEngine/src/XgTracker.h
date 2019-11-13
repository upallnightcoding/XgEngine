#pragma once

#include "Xg.h"

class XgTracker
{
public:
	XgTracker();
	virtual ~XgTracker();

public:
	void set(GLFWwindow* window);

	virtual void update(vec3 &eye, vec3 &center, vec3 &up) = 0;

protected:
	GLFWwindow* window;
};

