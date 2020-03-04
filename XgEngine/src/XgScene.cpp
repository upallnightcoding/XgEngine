#include "XgScene.h"



XgScene::XgScene()
{
	mode = GL_FILL;
}

XgScene::~XgScene()
{
}

void XgScene::setLightPosition(float x, float y, float z)
{
	light.setPosition(x, y, z);
}

/*****************************************************************************
setCameraPosition()
*****************************************************************************/
void XgScene::setCameraPosition(float x, float y, float z)
{
	camera.setPosition(x, y, z);
}

/*****************************************************************************
add()
*****************************************************************************/
void XgScene::add(XgObject *object)
{
	objectList.push_back(object);
}

/*****************************************************************************
add()
*****************************************************************************/
void XgScene::add(XgTracker *track)
{
	camera.add(track);
}

/*****************************************************************************
add()
*****************************************************************************/
void XgScene::add(XgRail *rail)
{
	light.add(rail);
}

/*****************************************************************************
create()
*****************************************************************************/
void XgScene::create(GLFWwindow* window, int screenWidth, int screenHeight)
{
	glPolygonMode(GL_FRONT_AND_BACK, mode);

	camera.create(window);

	for (auto object : objectList) {
		object->create();
	}

}

/*****************************************************************************
render()
*****************************************************************************/
void XgScene::render(float &deltaTime, int &updates)
{

	while (deltaTime >= 1.0) {
		camera.update();
		light.update();

		for (auto object : objectList) {	
			object->update(deltaTime);
		}

		updates++;
		deltaTime--;
	}

	// - Render at maximum possible frames
	for (auto object : objectList) {
		object->render(light, camera);
	}

}
