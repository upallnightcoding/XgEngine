#pragma once
#include "XgAction.h"
class XgActionMove :
	public XgAction
{
public:
	XgActionMove(float dx, float dy);
	XgActionMove(float dx, float dy, float dz);
	virtual ~XgActionMove();

public:
	void update(float deltaTime, XgTransform &transform);

private:
	float dx;
	float dy;
	float dz;
};

