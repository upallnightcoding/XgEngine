#include "XgLight.h"



XgLight::XgLight()
{
	position = vec3(0.0, 1.0, 0.0);
	colour = vec3(1.0);
}


XgLight::~XgLight()
{
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgLight::add(XgRail *rail)
{
	if (rail != NULL) {
		rails.push_back(rail);
	}
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgLight::update()
{
	for (auto rail : rails) {
		rail->update(position, colour);
	}
}

void XgLight::setPosition(float x, float y, float z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}

/*****************************************************************************
getColour() -
*****************************************************************************/
vec3 XgLight::getColour()
{
	return(colour);
}

/*****************************************************************************
getPosition() -
*****************************************************************************/
vec3 XgLight::getPosition()
{
	return(position);
}
