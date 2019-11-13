#pragma once
#include "XgAction.h"
class XgActionGlow :
	public XgAction
{
public:
	XgActionGlow();
	virtual ~XgActionGlow();

public:
	virtual void update(XgTransform &transform);
};

