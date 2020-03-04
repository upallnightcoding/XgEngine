#pragma once

#include "Xg.h"
#include "XgState.h"

class XgFramework
{
public:
	XgFramework();
	virtual ~XgFramework();

public:
	void add(XgState *state);
	XgBehavior *update();

private:
	map<string, XgState*> states;
	XgState *current;
};

