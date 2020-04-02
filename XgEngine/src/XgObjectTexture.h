#pragma once

#include "Xg.h"

class XgObjectTexture
{
public:
	XgObjectTexture(string texturePath);
	virtual ~XgObjectTexture();

	void create();
	void render();

private:
	void readImage();
	void setTextureParameters();

private:
	unsigned int texture;
	string texturePath;
};

