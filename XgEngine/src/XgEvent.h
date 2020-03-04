#pragma once

#include "Xg.h"

class XgEvent
{
public:
	XgEvent(string nextState);
	virtual ~XgEvent();

public:
	virtual bool hasOccured() = 0;
	string getNextState();

private:
	string nextState;
};

