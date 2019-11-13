#include "XgRailPosition.h"



XgRailPosition::XgRailPosition(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}


XgRailPosition::~XgRailPosition()
{
}

/*****************************************************************************
update() - 
*****************************************************************************/
void XgRailPosition::update(vec3 &position, vec3 &colour)
{
	position = vec3(x, y, z);
}
