#include "XgScene.h"

XgScene::XgScene()
{
	generalShader = new XgShader("GeneralVertext.shader");
	shadowShader = new XgShader("ShadowMap.shader");
	shadowTexture = new XgShadowTexture();
}

XgScene::~XgScene()
{
	delete generalShader;

	delete shadowShader;

	delete shadowTexture;
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

	shadowShader->create();

	shadowTexture->create();

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

	renderShadows();

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
useShadowShader()
*****************************************************************************/
void XgScene::renderShadows()
{
	shadowTexture->render(light);

	mat4 lightSpaceMatrix = shadowTexture->getLightSpaceMatrix();

	shadowShader->use();

	shadowShader->uniform("u_LightSpaceMatrix", lightSpaceMatrix);

	glViewport(0, 0, 1024, 1024);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_POLYGON_OFFSET_FILL);
	glPolygonOffset(2.0f, 4.0f);

	renderObjects(shadowShader);

	glDisable(GL_POLYGON_OFFSET_FILL);
}

/*****************************************************************************
useGeneralShader()
*****************************************************************************/
void XgScene::useGeneralShader(XgScreenSize &screenSize)
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	screenSize.viewPort();

	generalShader->use();

	mat4 biasMatrix(
		0.5, 0.0, 0.0, 0.0,
		0.0, 0.5, 0.0, 0.0,
		0.0, 0.0, 0.5, 0.0,
		0.5, 0.5, 0.5, 1.0
	);

	mat4 depthBiasMVP = biasMatrix * shadowTexture->getLightSpaceMatrix();

	//glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, Texture);
	// Set our "myTextureSampler" sampler to use Texture Unit 0
	//glUniform1i(TextureID, 0);
	generalShader->uniform("u_Texture", 0);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, shadowTexture->depthTexture());
	//glUniform1i(ShadowMapID, 1);
	generalShader->uniform("shadowMap", 1);

	generalShader->uniform("DepthBiasMVP", depthBiasMVP);

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
