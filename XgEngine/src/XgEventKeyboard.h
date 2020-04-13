#pragma once
#include "XgEvent.h"
class XgEventKeyboard :
	public XgEvent
{
public:
	XgEventKeyboard(string nextState, int targetKey);
	virtual ~XgEventKeyboard();

public:
	virtual bool hasOccured();

private:
	int targetKey;
	bool keyHasAlreadyBeenPressed;
};

