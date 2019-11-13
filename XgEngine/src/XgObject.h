#pragma once

#include "XgData.h"
#include "XgTransform.h"
#include "XgBehavior.h"
#include "XgShader.h"
#include "XgTexture.h"

class XgObject :
	public XgData
{
public:
	XgObject(XgObjectInfo &objectInfo);
	virtual ~XgObject();

public:
	void render(XgLight &light, XgCamera &camera);
	void update(double deltaTime);
	void add(XgAction *action);
	void create();

	void move(float x, float y, float z);
	void turn(float x, float y, float z);

private:
	XgTransform transform;
	XgBehavior *behavior;

	XgShader *shader;
	XgTexture *texture;
};

inline void XgObject::move(float x, float y, float z)
{
	transform.move(x, y, z);
}

inline void XgObject::turn(float x, float y, float z)
{
	transform.turn(x, y, z);
}


