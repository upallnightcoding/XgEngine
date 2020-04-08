#pragma once

#include "Xg.h"

#include "XgObject.h"
#include "XgShader.h"
#include "XgCamera.h"
#include "XgShadow.h"

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
	void renderObjects(XgShader *shader, XgRenderMode mode);
	void updateDeltaTime(float &deltaTime, int &updates);

private:
	vector<XgObject*> objectList;
	XgCamera camera;
	XgLighting light;
	XgShader *shader;
	XgShadow *shadow;
	XgShader *depthTest;
	XgRenderContext *renderContext;
};

inline void XgScene::setLightPosition(float x, float y, float z)
{
	light.setPosition(x, y, z);
}

/*****************************************************************************
setCameraPosition()
*****************************************************************************/
inline void XgScene::setCameraPosition(float x, float y, float z)
{
	camera.setPosition(x, y, z);
}

/*****************************************************************************
add()
*****************************************************************************/
inline void XgScene::add(XgObject *object)
{
	objectList.push_back(object);
}

/*****************************************************************************
add()
*****************************************************************************/
inline void XgScene::add(XgTracker *track)
{
	camera.add(track);
}

/*****************************************************************************
add()
*****************************************************************************/
inline void XgScene::add(XgLight *rail)
{
	light.add(rail);
}