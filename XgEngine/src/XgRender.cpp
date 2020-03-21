#include "XgRender.h"

#include "Xg.h"

XgRender::XgRender()
{
}


XgRender::~XgRender()
{
}

/*****************************************************************************
create() -
*****************************************************************************/
void XgRender::create(GLFWwindow* window)
{
	scene->create(window);
}

/*****************************************************************************
animate() -
*****************************************************************************/
void XgRender::animate(XgScreenSize &screenSize, float &deltaTime, int &updates)
{
	scene->render(screenSize, deltaTime, updates);
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgRender::add(XgScene *scene) {
	this->scene = scene;
}
