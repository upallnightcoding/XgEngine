#pragma once

#include "Xg.h"
#include "XgShader.h"
#include "XgLighting.h"

class XgShadowTexture
{
public:
	XgShadowTexture();
	virtual ~XgShadowTexture();

public:
	void create();
	void render(XgLighting &light);

	mat4 getLightSpaceMatrix();

	unsigned int depthTexture();
	
private:
	unsigned int pDepthMapFBO;
	unsigned int pDepthTexture;
	mat4 pLightSpaceMatrix;
};

inline mat4 XgShadowTexture::getLightSpaceMatrix()
{
	return(pLightSpaceMatrix);
}

inline unsigned int XgShadowTexture::depthTexture()
{
	return(pDepthTexture);
}

