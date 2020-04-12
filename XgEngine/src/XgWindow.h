#pragma once

#include "Xg.h"
#include "XgScreenSize.h"

class XgWindow
{
public:
	XgWindow(int screenWidth, int screenHeight);
	virtual ~XgWindow();

public:
	int startAnimation();

protected:
	virtual void renderScreen(float &deltaTime, int &updates) = 0;
	virtual void initRender(GLFWwindow* window) = 0;
	virtual void closeRender() = 0;

protected:
	XgScreenSize *screenSize;

private:
	void renderLoop(GLFWwindow* window);
};

