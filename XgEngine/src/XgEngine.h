#pragma once

#include "XgRender.h"
#include "XgWindow.h"
#include "XgShader.h"
#include "XgScene.h"

/*****************************************************************************
classs XgEngine
*****************************************************************************/

class XgEngine :
	public XgWindow
{
public:
	XgEngine(int screenWidth, int screenHeight);
	virtual ~XgEngine();

public:
	void add(XgScene *scene);

protected:
	virtual void initRender(GLFWwindow* window);
	virtual void renderScreen(float &deltaTime, int &updates);
	virtual void closeRender();

private:
	XgRender render;
	XgScene *scene;
};
