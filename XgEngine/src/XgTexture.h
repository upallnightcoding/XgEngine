#pragma once

#include "Xg.h"

class XgTexture
{
public:
	XgTexture(string texturePath);
	virtual ~XgTexture();

	void create();
	void render();

private:
	unsigned int texture;
	string texturePath;
};

