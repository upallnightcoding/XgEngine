#pragma once

#include "Xg.h"

class XgObjectTexture
{
public:
	XgObjectTexture(string texturePath);
	virtual ~XgObjectTexture();

	void create();
	void render();

	unsigned int getTexture();

private:
	void readImage();
	void setTextureParameters();

private:
	unsigned int texture;
	string texturePath;
};

inline unsigned int XgObjectTexture::getTexture()
{
	return(texture);
}