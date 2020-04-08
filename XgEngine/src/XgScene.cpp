#include "XgScene.h"

float planeVertices[] = {
	// positions            // normals         // texcoords
	 25.0f, -0.5f,  25.0f,  0.0f, 1.0f, 0.0f,  25.0f,  0.0f,
	-25.0f, -0.5f,  25.0f,  0.0f, 1.0f, 0.0f,   0.0f,  0.0f,
	-25.0f, -0.5f, -25.0f,  0.0f, 1.0f, 0.0f,   0.0f, 25.0f,

	 25.0f, -0.5f,  25.0f,  0.0f, 1.0f, 0.0f,  25.0f,  0.0f,
	-25.0f, -0.5f, -25.0f,  0.0f, 1.0f, 0.0f,   0.0f, 25.0f,
	 25.0f, -0.5f, -25.0f,  0.0f, 1.0f, 0.0f,  25.0f, 25.0f
};

unsigned int quadVAO = 0;
unsigned int quadVBO;

void renderQuad(unsigned int depthMap)
{
	if (quadVAO == 0)
	{
		float quadVertices[] = {
			// positions        // texture Coords
			-2.0f,  2.0f, -2.0f, 0.0f, 1.0f,
			-2.0f, -2.0f, -2.0f, 0.0f, 0.0f,
			 2.0f,  2.0f, -2.0f, 1.0f, 1.0f,
			 2.0f, -2.0f, -2.0f, 1.0f, 0.0f,
		};

		// setup plane VAO
		glGenVertexArrays(1, &quadVAO);
		glGenBuffers(1, &quadVBO);
		glBindVertexArray(quadVAO);
		glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	}

	glBindVertexArray(quadVAO);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, depthMap);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glBindVertexArray(0);
}

XgScene::XgScene()
{
	shader = new XgShader("GeneralShader.shader");
	shadow = new XgShadow();
	depthTest = new XgShader("DepthMap.shader");

}

XgScene::~XgScene()
{
	delete shader;

	delete shadow;

	delete depthTest;
}

/*****************************************************************************
create()
*****************************************************************************/
void XgScene::create(GLFWwindow* window)
{
	renderContext = new XgRenderContext();

	camera.create(window);

	for (auto object : objectList) {
		object->create();
	}

	shadow->create();

	shader->create();

	depthTest->create();
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

	// Render the scene shadow
	//------------------------
	//shadow->render(light);

	// Render the scene shadow texture
	//--------------------------------
	//renderObjects(shadow->getShader(), XgRenderMode::SHADOW);
	//glBindFramebuffer(GL_FRAMEBUFFER, 0);

	// Use the general shader for render the scene
	//--------------------------------------------
	useGeneralShader(screenSize);

	// Render the scene objects and behavior
	//--------------------------------------
	renderObjects(shader, XgRenderMode::OBJECT);

	//shadow->getShader()->use();
	//debugDepthQuad.setFloat("near_plane", near_plane);
	//debugDepthQuad.setFloat("far_plane", far_plane);
	//glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, shadow->depthTexture());
	//renderQuad();
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
void XgScene::renderObjects(XgShader *shader, XgRenderMode mode)
{
	// Render all the objects in the scene
	//------------------------------------
	for (auto object : objectList) {
		object->render(shader, mode);
	}
}

/*****************************************************************************
useGeneralShader()
*****************************************************************************/
void XgScene::useGeneralShader(XgScreenSize &screenSize)
{
	//glBindFramebuffer(GL_FRAMEBUFFER, 0);

	

	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK); 
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	mat4 biasMatrix(
		0.5, 0.0, 0.0, 0.0,
		0.0, 0.5, 0.0, 0.0,
		0.0, 0.0, 0.5, 0.0,
		0.5, 0.5, 0.5, 1.0
	);

	mat4 depthBiasMVP = biasMatrix * shadow->getLightSpaceMatrix();

	//glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, Texture);
	// Set our "myTextureSampler" sampler to use Texture Unit 0
	//glUniform1i(TextureID, 0);
	
	//glActiveTexture(GL_TEXTURE1);
	//glBindTexture(GL_TEXTURE_2D, shadowTexture->depthTexture());
	//glUniform1i(ShadowMapID, 1);

	screenSize.viewPort();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	depthTest->use();
	depthTest->uniform("depthMap", 0);
	depthTest->uniform("near_plane", 0.1f);
	depthTest->uniform("far_plane", 100.0f);

	renderQuad(shadow->depthTexture());
	
	shader->use();
	//shader->uniform("u_Texture", 0);
	//shader->uniform("shadowMap", 1);
	//shader->uniform("DepthBiasMVP", depthBiasMVP);

	shader->uniform("projection", screenSize.getPerspective());
	shader->uniform("view", camera.getView());
	shader->uniform("lightSpaceMatrix", shadow->getLightSpaceMatrix());
	shader->uniform("diffuseTexture", 0);
	shader->uniform("shadowMap", 1);
	//shader->uniform("lightPos", screenSize.getPerspective() * camera.getView() * vec4(light.position(), 1.0));
	shader->uniform("lightPos", light.position());
	shader->uniform("viewPos", camera.getPosition());

	//shader->uniform(XgConstant::U_PROJECT, screenSize.getPerspective());
	
	// Define Light Telemetry
	//-----------------------
	//shader->uniform(XgConstant::U_LIGHT_COLOR, light.colour());
	//shader->uniform(XgConstant::U_LIGHT_POSITION, light.position());

	// Define Camera Telemetry
	//------------------------
	//shader->uniform(XgConstant::U_CAMERA_POSITION, camera.getPosition());
	//shader->uniform(XgConstant::U_CAMERA_VIEW, camera.getView());

	//glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, woodTexture);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, shadow->depthTexture());

	
}
