#include "XgFsm.h"



XgFsm::XgFsm()
{
	this->current = NULL;
}


XgFsm::~XgFsm()
{
}

/*****************************************************************************
add()
*****************************************************************************/
void XgFsm::add(XgState *state)
{
	if (state != NULL) {
		if (current == NULL) {
			current = state;
		}

		states[state->getName()] = state;
	}
}
