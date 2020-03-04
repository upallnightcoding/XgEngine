#include "XgEventGoto.h"



XgEventGoto::XgEventGoto(string nextState) : XgEvent(nextState)
{
}


XgEventGoto::~XgEventGoto()
{
}

/*****************************************************************************
hasOccured() -
*****************************************************************************/
bool XgEventGoto::hasOccured()
{
	return(true);
}
