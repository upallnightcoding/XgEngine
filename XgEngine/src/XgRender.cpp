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
void XgRender::create(GLFWwindow* window, int screenWidth, int screenHeight)
{
	scene->create(window, screenWidth, screenHeight);
}

/*****************************************************************************
animate() -
*****************************************************************************/
void XgRender::animate(double &deltaTime, int &updates)
{
	scene->render(deltaTime, updates);
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgRender::add(XgScene *scene) {
	this->scene = scene;
}
