#include "XgEventFrames.h"



XgEventFrames::XgEventFrames(string nextState, int tickCount) : XgEvent(nextState)
{
	this->tickCount = tickCount;
	this->ticks = 0;
}


XgEventFrames::~XgEventFrames()
{
}

/*****************************************************************************
hasOccured() -
*****************************************************************************/
bool XgEventFrames::hasOccured()
{
	bool occured = false;

	if (ticks++ == tickCount) {
		occured = true;
		ticks = 0;
	}

	return(occured);
}
