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

	void fillMode();
	void lineMode();
	void pointMode();

private:
	vector<XgObject*> objectList;
	XgCamera camera;
	XgLight light;

	GLenum mode;
};

inline void XgScene::fillMode()
{
	mode = GL_FILL;
}

inline void XgScene::lineMode()
{
	mode = GL_LINE;
}

inline void XgScene::pointMode()
{
	mode = GL_POINT;
}

