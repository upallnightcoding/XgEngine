#include "XgEngine.h"

#include "Xg.h"

using namespace std;

XgEngine::XgEngine(int screenWidth, int screenHeight) 
	: XgWindow(screenWidth, screenHeight)
{
	cout << "XgEngine Constructor ..." << endl;

	scene = NULL;
}

XgEngine::~XgEngine()
{
}

/*****************************************************************************
render()
*****************************************************************************/
void XgEngine::initRender(GLFWwindow* window)
{
	render.create(window);
}

/*****************************************************************************
render()
*****************************************************************************/
void XgEngine::renderScreen(float &deltaTime, int &updates)
{
	render.animate(*screenSize, deltaTime, updates);
}

/*****************************************************************************
render()
*****************************************************************************/
void XgEngine::closeRender()
{
	
}

/*****************************************************************************
render()
*****************************************************************************/
void XgEngine::add(XgScene *scene)
{
	if (scene != NULL) {
		render.add(scene);
	}
}
