#include "XgScene.h"



XgScene::XgScene()
{
	generalShader = new XgShader("GeneralVertext.shader");
}

XgScene::~XgScene()
{
	delete generalShader;
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
void XgScene::add(XgLight *rail)
{
	light.add(rail);
}

/*****************************************************************************
create()
*****************************************************************************/
void XgScene::create(GLFWwindow* window)
{
	renderContext = new XgRenderContext();

	generalShader->create();

	camera.create(window);

	for (auto object : objectList) {
		object->create();
	}
}

/*****************************************************************************
render() - Render all the objects in the scene.  Make sure that any user
device input has been captured and has updated, either the camer, light or
object.  Once the delta time has reached its uniform time stamp, draw the
actual scene.
*****************************************************************************/
void XgScene::render(XgScreenSize &screenSize, float &deltaTime, int &updates)
{
	// Set the context screen size in case it changed
	//-----------------------------------------------
	renderContext->screenSize(&screenSize);

	// Update all scene objects until we reach the uniform deltatime
	//--------------------------------------------------------------
	updateDeltaTime(deltaTime, updates);

	// Use the general shader for render the scene
	//--------------------------------------------
	useGeneralShader(screenSize);

	// Render the scene objects and behavior
	//--------------------------------------
	renderObjects(generalShader);
}

/*****************************************************************************
updateDeltaTime() -
*****************************************************************************/
void XgScene::updateDeltaTime(float &deltaTime, int &updates)
{
	while (deltaTime >= 1.0) {
		camera.update(renderContext);
		light.update();

		for (auto object : objectList) {
			object->update(deltaTime);
		}

		updates++;
		deltaTime--;
	}
}

/*****************************************************************************
renderObjects() - Traverse through each object in the scene and render it
with the given shader.
*****************************************************************************/
void XgScene::renderObjects(XgShader *shader)
{
	// Render all the objects in the scene
	//------------------------------------
	for (auto object : objectList) {
		object->render(shader);
	}
}

/*****************************************************************************
useGeneralShader()
*****************************************************************************/
void XgScene::useGeneralShader(XgScreenSize &screenSize)
{
	generalShader->use();

	generalShader->uniform(XgConstant::U_PROJECT, screenSize.getPerspective());

	// Define Light Telemetry
	//-----------------------
	generalShader->uniform(XgConstant::U_LIGHT_COLOR, light.getColour());
	generalShader->uniform(XgConstant::U_LIGHT_POSITION, light.getPosition());

	// Define Camera Telemetry
	//------------------------
	generalShader->uniform(XgConstant::U_CAMERA_POSITION, camera.getPosition());
	generalShader->uniform(XgConstant::U_CAMERA_VIEW, camera.getView());
}
