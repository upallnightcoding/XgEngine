#pragma once

#include "Xg.h"

#include "XgObject.h"
#include "XgShader.h"
#include "XgCamera.h"

class XgScene
{
public:
	XgScene();
	virtual ~XgScene();

public:
	void addObject(XgObject *object);
	void addCamera(XgTracker *track);
	void add(XgRail *rail);

	void render(double &deltaTime, int &updates);
	void create(GLFWwindow* window, int screenWidth, int screenHeight);

	void setCameraPosition(float x, float y, float z);

	void setLightPosition(float x, float y, float z);

private:
	vector<XgObject*> objectList;
	XgCamera camera;
	XgLight light;
};

