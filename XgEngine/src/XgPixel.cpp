#include "XgPixel.h"



XgPixel::XgPixel(int screenWidth, int screenHeight)
	: XgWindow(screenWidth, screenHeight)
{
	camera.setPosition(0.0, 0.0, -50.0);
}

XgPixel::~XgPixel()
{
	delete paper;
}

/*****************************************************************************
render()
*****************************************************************************/
void XgPixel::initRender(GLFWwindow* window)
{
	camera.create(window);

	paper->create();
}

/*****************************************************************************
render()
*****************************************************************************/
void XgPixel::renderScreen(float &deltaTime, int &updates)
{
	updateDeltaTime(deltaTime, updates);

	paper->animate();
}

/*****************************************************************************
render()
*****************************************************************************/
void XgPixel::closeRender()
{

}

/*****************************************************************************
add() -
*****************************************************************************/
void XgPixel::add(XgPaper *paper)
{
	this->paper = paper;
}

/*****************************************************************************
render()
*****************************************************************************/
void XgPixel::updateDeltaTime(float &deltaTime, int &fps)
{
	while (deltaTime >= 1.0) {
		//camera.update(renderContext);
		//light.update();

		//for (auto object : objectList) {
			//object->update(deltaTime);
		//}

		fps++;
		deltaTime--;
	}
}