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

		states[state->name()] = state;
	}
}

/*****************************************************************************
update()
*****************************************************************************/
XgBehavior *XgFramework::update()
{
	XgBehavior *behavior = current->behavior();

	string nextState = current->update();
	if (nextState != XgConstant::EMPTY_STRING) {
		current = states[nextState];

		if (current != NULL) {
			behavior = current->behavior();
		}
	}

	return(behavior);
}
