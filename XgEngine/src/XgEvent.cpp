#include "XgEvent.h"



XgEvent::XgEvent(string nextState)
{
	this->nextState = nextState;
}


XgEvent::~XgEvent()
{
}

/*****************************************************************************
getNextState() -
*****************************************************************************/
string XgEvent::getNextState()
{
	return(nextState);
}
