#include "XgState.h"



XgState::XgState(string name)
{
	this->name = name;
	this->behavior = new XgBehavior();
}


XgState::~XgState()
{
}

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
