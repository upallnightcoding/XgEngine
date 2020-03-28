#include "XgLightPosition.h"



XgLightPosition::XgLightPosition(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}


XgLightPosition::~XgLightPosition()
{
}

/*****************************************************************************
update() - 
*****************************************************************************/
void XgLightPosition::update(vec3 &position, vec3 &colour)
{
	position = vec3(x, y, z);
}
