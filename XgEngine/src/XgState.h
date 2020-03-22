#pragma once

#include "Xg.h"
#include "XgBehavior.h"
#include "XgEvent.h"

/*****************************************************************************
class XgState
*****************************************************************************/
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
	string name();
	XgBehavior *behavior();

private:
	string pName;
	XgBehavior *pBehavior;
	vector<XgEvent*> pEventList;
};

/*****************************************************************************
getName() - Returns the name of the state.
*****************************************************************************/
inline string XgState::name()
{
	return(pName);
}

/*****************************************************************************
getBehavior() - Returns the behavior of the state
*****************************************************************************/
inline XgBehavior *XgState::behavior()
{
	return(pBehavior);
}