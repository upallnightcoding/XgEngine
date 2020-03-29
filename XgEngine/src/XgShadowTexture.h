#pragma once

#include "Xg.h"
#include "XgShader.h"

class XgShadowTexture
{
public:
	XgShadowTexture();
	virtual ~XgShadowTexture();

public:
	void create();
	void render(vec3 lightPos);
	
private:
	unsigned int depthMapFBO;
	XgShader *shader;
};

