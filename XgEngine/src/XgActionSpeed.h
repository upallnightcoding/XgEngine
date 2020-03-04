#pragma once
#include "XgAction.h"
#include "XgTransform.h"

class XgActionSpeed :
	public XgAction
{
public:
	XgActionSpeed(float speed);
	virtual ~XgActionSpeed();

public:
	virtual void update(float deltaTime, XgTransform &transform);

private:
	float speed;
};

