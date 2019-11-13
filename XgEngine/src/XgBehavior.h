#pragma once

#include "Xg.h"
#include "XgAction.h"

class XgBehavior
{
public:
	XgBehavior();
	virtual ~XgBehavior();

public:
	void add(XgAction *action);
	void update(double deltaTime, XgTransform &transform);

private:
	vector<XgAction*> behaviorList;
};

