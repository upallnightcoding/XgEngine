#pragma once

#include "Xg.h"

class XgWindow
{
public:
	XgWindow(int screenWidth, int screenHeight);
	virtual ~XgWindow();

public:
	int startRenderingWindow();
	void setScreenSize(int screenWidth, int screenHeight);

protected:
	virtual void renderScreen(double &deltaTime, int &updates) = 0;
	virtual void initRender(GLFWwindow* window) = 0;
	virtual void closeRender() = 0;

protected:
	int screenWidth;
	int screenHeight;
};

