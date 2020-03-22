#pragma once

#include "XgObject.h"


class XgObjectFactory
{
public:
	XgObjectFactory();
	virtual ~XgObjectFactory();

public:
	XgObject *sphere(string textureFile);
	XgObject *monkey(string textureFile);
	XgObject *cube(string textureFile);
	XgObject *rectangle(string textureFile);
	XgObject *triangle(string textureFile);
	XgObject *terrain(string textureFile, int nPoints, float size, float smooth);
};

