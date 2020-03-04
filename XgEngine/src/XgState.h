#pragma once

#include "Xg.h"
#include "XgBehavior.h"
#include "XgEvent.h"

class XgState
{
public:
	XgState(string name);
	virtual ~XgState();

public:
	void add(XgAction *action);
	void add(XgBehavior *behavior);
	void add(XgEvent *event);

	string update();

public:
	string getName();
	XgBehavior *getBehavior();

private:
	string name;
	XgBehavior *behavior;
	vector<XgEvent*> eventList;
};

