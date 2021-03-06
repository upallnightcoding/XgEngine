#pragma once
#include "XgAction.h"
class XgActionSpin :
	public XgAction
{
public:
	XgActionSpin(float dx, float dy, float dz);
	virtual ~XgActionSpin();

public:
	virtual void update(float deltaTime, XgTransform &transform);

private:
	float dx;
	float dy;
	float dz;
};

