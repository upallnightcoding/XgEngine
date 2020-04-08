#include "XgShadow.h"

const unsigned int SHADOW_WIDTH = 1024, SHADOW_HEIGHT = 1024;

XgShadow::XgShadow()
{
	shader = new XgShader("ShadowMap.shader");
}

XgShadow::~XgShadow()
{
}

void XgShadow::create()
{
	shader->create();

	glGenFramebuffers(1, &pDepthMapFBO);
	
	glGenTextures(1, &pDepthMap);
	glBindTexture(GL_TEXTURE_2D, pDepthMap);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	glBindFramebuffer(GL_FRAMEBUFFER, pDepthMapFBO);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, pDepthMap, 0);
		glDrawBuffer(GL_NONE);
		glReadBuffer(GL_NONE);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void XgShadow::render(XgLighting &light)
{
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glBindFramebuffer(GL_FRAMEBUFFER, pDepthMapFBO);

	float nearPlane = 1.0f, farPlane = 7.5f;
	vec3 lightPos = light.position();

	mat4 lightProjection = ortho(-10.0f, 10.0f, -10.0f, 10.0f, nearPlane, farPlane);
	mat4 lightView = lookAt(lightPos, vec3(0.0f), vec3(0.0, 1.0, 0.0));
	pLightSpaceMatrix = lightProjection * lightView;

	shader->use();
	shader->uniform("u_LightSpaceMatrix", pLightSpaceMatrix);

	glViewport(0, 0, 1000, 600);
	glBindFramebuffer(GL_FRAMEBUFFER, pDepthMapFBO);
	glClear(GL_DEPTH_BUFFER_BIT);

	glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, woodTexture);
	//renderScene(simpleDepthShader);
	//glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void XgShadow::deAllocate()
{

}
