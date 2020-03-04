#include "XgFramework.h"



XgFramework::XgFramework()
{
	this->current = NULL;
}


XgFramework::~XgFramework()
{
}

/*****************************************************************************
add()
*****************************************************************************/
void XgFramework::add(XgState *state)
{
	if (state != NULL) {
		if (current == NULL) {
			current = state;
		}

		states[state->getName()] = state;
	}
}

/*****************************************************************************
update()
*****************************************************************************/
XgBehavior *XgFramework::update()
{
	string nextState = current->update();
	XgBehavior *behavior = NULL;

	if (nextState != XgConstant::EMPTY_STRING) {
		current = states[nextState];

		if (current != NULL) {
			behavior = current->getBehavior();
		}
	}

	return(behavior);
}
