#pragma once

#include "Xg.h"

#include "XgObject.h"
#include "XgShader.h"
#include "XgCamera.h"

/*****************************************************************************
classs XgScene
*****************************************************************************/

class XgScene
{
public:
	XgScene();
	virtual ~XgScene();

public:
	void add(XgObject *object);
	void add(XgTracker *track);
	void add(XgLight *rail);

	void render(XgScreenSize &screenSize, float &deltaTime, int &updates);
	void create(GLFWwindow* window);

	void setCameraPosition(float x, float y, float z);

	void setLightPosition(float x, float y, float z);

private:
	void useGeneralShader(XgScreenSize &screenSize);
	void renderObjects(XgShader *shader);
	void updateDeltaTime(float &deltaTime, int &updates);

private:
	vector<XgObject*> objectList;
	XgCamera camera;
	XgLighting light;
	XgShader *generalShader;

	XgRenderContext *renderContext;
};


