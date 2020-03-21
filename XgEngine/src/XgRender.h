#pragma once

#include "XgScene.h"

class XgRender 
{
public:
	XgRender();
	virtual ~XgRender();

public:
	void animate(XgScreenSize &screenSize, float &deltaTime, int &updates);
	void add(XgScene *scene);
	void create(GLFWwindow* window);

private:
	XgScene *scene;
};

