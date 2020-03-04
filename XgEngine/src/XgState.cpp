#include "XgState.h"



XgState::XgState(string name)
{
	this->name = name;
	this->behavior = new XgBehavior();
}


XgState::~XgState()
{
	if (behavior != NULL) {
		delete behavior;
	}

	for (XgEvent *event : eventList) {
		if (event != NULL) {
			delete event;
		}
	}
}

/*****************************************************************************
getBehavior() -
*****************************************************************************/
XgBehavior *XgState::getBehavior()
{
	return(behavior);
}

/*****************************************************************************
update() -
*****************************************************************************/
string XgState::update()
{
	int nEvents = eventList.size();
	string nextState = XgConstant::EMPTY_STRING;

	for (int i = 0; (i < nEvents) && (nextState == XgConstant::EMPTY_STRING); i++) {
		XgEvent *event = eventList.at(i);
		if (event->hasOccured()) {
			nextState = event->getNextState();
		}
	}

	return(nextState);
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgState::add(XgEvent *event)
{
	if (event != NULL) {
		eventList.push_back(event);
	}
}

/*****************************************************************************
getName() -
*****************************************************************************/
string XgState::getName()
{
	return(name);
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgState::add(XgAction *action)
{
	behavior->add(action);
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgState::add(XgBehavior *behavior)
{
	this->behavior = behavior;
}
