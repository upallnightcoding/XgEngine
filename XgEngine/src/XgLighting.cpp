#include "XgLighting.h"



XgLighting::XgLighting()
{
	pPosition = vec3(0.0, 0.0, 0.0);
	pColour = vec3(1.0);
}


XgLighting::~XgLighting()
{
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgLighting::add(XgLight *rail)
{
	if (rail != NULL) {
		rails.push_back(rail);
	}
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgLighting::update()
{
	for (auto rail : rails) {
		rail->update(pPosition, pColour);
	}
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgLighting::setPosition(float x, float y, float z)
{
	pPosition.x = x;
	pPosition.y = y;
	pPosition.z = z;
}

