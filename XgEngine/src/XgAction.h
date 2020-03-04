#pragma once

#include "XgTransform.h"

class XgAction
{
public:
	XgAction();
	virtual ~XgAction();

public:
	virtual void update(float deltaTime, XgTransform &transform) = 0;
};

