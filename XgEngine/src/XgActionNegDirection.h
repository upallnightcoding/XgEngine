#pragma once
#include "XgAction.h"
#include "XgTransform.h"

class XgActionNegDirection :
	public XgAction
{
public:
	XgActionNegDirection();
	virtual ~XgActionNegDirection();

public:
	virtual void update(float deltaTime, XgTransform &transform);
};

