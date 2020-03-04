#pragma once

#include "XgScene.h"

class XgRender 
{
public:
	XgRender();
	virtual ~XgRender();

public:
	void animate(float &deltaTime, int &updates);
	void add(XgScene *scene);
	void create(GLFWwindow* window, int screenWidth, int screenHeight);

private:
	XgScene *scene;
};

