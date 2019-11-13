#pragma once

#include "Xg.h"
#include "XgBehavior.h"

class XgState
{
public:
	XgState(string name);
	virtual ~XgState();

public:
	void add(XgAction *action);

public:
	string getName();

private:
	string name;
	XgBehavior *behavior;
};

