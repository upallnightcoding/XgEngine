#pragma once

#include "Xg.h"

class XgWindow
{
public:
	XgWindow(int screenWidth, int screenHeight);
	virtual ~XgWindow();

public:
	int startAnimation();
	void setScreenSize(int screenWidth, int screenHeight);

protected:
	virtual void renderScreen(float &deltaTime, int &updates) = 0;
	virtual void initRender(GLFWwindow* window) = 0;
	virtual void closeRender() = 0;

protected:
	int screenWidth;
	int screenHeight;
};

