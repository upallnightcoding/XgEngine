#include "XgActionSpin.h"



XgActionSpin::XgActionSpin(float dx, float dy, float dz)
{
	this->dx = dx;
	this->dy = dy;
	this->dz = dz;
}

XgActionSpin::~XgActionSpin()
{
}

/*****************************************************************************
render()
*****************************************************************************/
void XgActionSpin::update(double deltaTime, XgTransform &transform)
{
	transform.turn(dx, dy, dz);
}
