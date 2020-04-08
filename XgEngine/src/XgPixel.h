#pragma once
#include "XgWindow.h"
#include "XgSprite.h"
#include "XgPaper.h"

class XgPixel :
	public XgWindow
{
public:
	XgPixel(int screenWidth, int screenHeight);
	virtual ~XgPixel();

public:
	void add(XgPaper *paper);

protected:
	virtual void initRender(GLFWwindow* window);
	virtual void renderScreen(float &deltaTime, int &fps);
	virtual void closeRender();

private:
	void updateDeltaTime(float &deltaTime, int &updates);

private:
	XgCamera camera;
	XgPaper *paper;
};

