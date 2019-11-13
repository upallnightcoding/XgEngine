#pragma once

#include "Xg.h"
#include "XgState.h"

class XgFsm
{
public:
	XgFsm();
	virtual ~XgFsm();

public:
	void add(XgState *state);

private:
	map<string, XgState*> states;
	XgState *current;
};

