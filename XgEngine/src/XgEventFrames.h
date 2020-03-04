#pragma once
#include "XgEvent.h"

class XgEventFrames :
	public XgEvent
{
public:
	XgEventFrames(string nextState, int tickCount);
	virtual ~XgEventFrames();

public:
	virtual bool hasOccured();

private:
	int tickCount;
	int ticks;
};

