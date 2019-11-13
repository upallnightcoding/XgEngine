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
	render.create(window, screenWidth, screenHeight);
}

/*****************************************************************************
render()
*****************************************************************************/
void XgEngine::renderScreen(double &deltaTime, int &updates)
{
	render.animate(deltaTime, updates);
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
