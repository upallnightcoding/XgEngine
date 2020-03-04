#pragma once
#include "XgEvent.h"

class XgEventGoto :
	public XgEvent
{
public:
	XgEventGoto(string nextState);
	virtual ~XgEventGoto();

public:
	bool hasOccured();
};

