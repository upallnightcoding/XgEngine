#include "XgPixel.h"

XgPixel::XgPixel(int screenWidth, int screenHeight)
	: XgWindow(screenWidth, screenHeight)
{
	shader = new XgShader("sprite.shader");
}

XgPixel::~XgPixel()
{
	delete paper;

	delete shader;
}

/*****************************************************************************
render()
*****************************************************************************/
void XgPixel::initRender(GLFWwindow* window)
{
	paper->create(window);

	camera.setPosition(5.0);

	camera.create(window);

	shader->create();

	shader->use();

	shader->uniform("u_View", camera.getView());

	shader->uniform("u_Projection", screenSize->getPerspective());

	renderContext = new XgRenderContext();
}

/*****************************************************************************
render()
*****************************************************************************/
void XgPixel::renderScreen(float &deltaTime, int &updates)
{
	updateDeltaTime(deltaTime, updates);

	paper->animate(shader);
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

		paper->update(deltaTime);

		//for (auto object : objectList) {
			//object->update(deltaTime);
		//}

		fps++;
		deltaTime--;
	}

	//float lag = deltaTime;
	//while (lag >= (1.0 / 60.0))
	//{
		
		//lag -= (1.0/ 60.0);
	//}
}