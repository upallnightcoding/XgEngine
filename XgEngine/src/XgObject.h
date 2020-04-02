#pragma once

#include "XgData.h"
#include "XgTransform.h"
#include "XgBehavior.h"
#include "XgShader.h"
#include "XgObjectTexture.h"
#include "XgFramework.h"

#include "Xg.h"

class XgObject
{
public:
	XgObject(XgObjectInfo &objectInfo);
	virtual ~XgObject();

public:
	void render(XgShader *shader, XgRenderMode mode);
	void update(float deltaTime);
	void add(XgAction *action);
	void add(XgFramework *framework);
	void create();

	void move(float x, float y, float z);
	void turn(float x, float y, float z);

	void scale(float x, float y, float z);
	void scale(float value);

private:
	XgTransform transform;
	XgBehavior *localBehavior;
	XgFramework *framework;

	XgObjectTexture *texture;
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

/*****************************************************************************
update() - Set the scale factor of the x, y, and z axis.
*****************************************************************************/
inline void XgObject::scale(float x, float y, float z)
{
	transform.scale(x, y, z);
}

/*****************************************************************************
scale() - Set the scale factor of the x, y, and z axis the same.
*****************************************************************************/
inline void XgObject::scale(float value)
{
	transform.scale(value);
}


