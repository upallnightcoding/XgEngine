#pragma once

#include "Xg.h"

class XgImageTexture
{
public:
	XgImageTexture(string texturePath);
	virtual ~XgImageTexture();

	void create();
	void render();

private:
	void readImage();
	void setTextureParameters();

private:
	unsigned int texture;
	string texturePath;
};

