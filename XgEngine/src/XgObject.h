#pragma once

#include "XgData.h"
#include "XgTransform.h"
#include "XgBehavior.h"
#include "XgShader.h"
#include "XgTexture.h"
#include "XgFramework.h"

class XgObject
{
public:
	XgObject(XgObjectInfo &objectInfo);
	virtual ~XgObject();

public:
	void render(XgLight &light, XgCamera &camera);
	void update(float deltaTime);
	void add(XgAction *action);
	void add(XgFramework *framework);
	void create();

	void move(float x, float y, float z);
	void turn(float x, float y, float z);

private:
	XgTransform transform;
	XgBehavior *behavior;
	XgFramework *framework;

	XgShader *shader;
	XgTexture *texture;
	XgData *data;
};

inline void XgObject::move(float x, float y, float z)
{
	transform.move(x, y, z);
}

inline void XgObject::turn(float x, float y, float z)
{
	transform.turn(x, y, z);
}


