#pragma once

#include "XgTransform.h"

class XgAction
{
public:
	XgAction();
	virtual ~XgAction();

public:
	virtual void update(double deltaTime, XgTransform &transform) = 0;
};

