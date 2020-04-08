#pragma once

#include "XgShader.h"
#include "XgLighting.h"

class XgShadow
{
public:
	XgShadow();
	virtual ~XgShadow();

public:
	void create();
	void render(XgLighting &light);
	void deAllocate();

	mat4 getLightSpaceMatrix();

	unsigned int depthTexture();

	XgShader *getShader();

private:
	XgShader *shader;

	unsigned int pDepthMapFBO;
	unsigned int pDepthMap;
	mat4 pLightSpaceMatrix;
};

inline XgShader *XgShadow::getShader()
{
	return(shader);
}

inline unsigned int XgShadow::depthTexture()
{
	return(pDepthMap);
}

inline mat4 XgShadow::getLightSpaceMatrix() 
{
	return(pLightSpaceMatrix);
}