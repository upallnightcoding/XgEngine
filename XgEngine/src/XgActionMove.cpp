#include "XgActionMove.h"



XgActionMove::XgActionMove(float dx, float dy, float dz)
{
	this->dx = dx;
	this->dy = dy;
	this->dz = dz;
}

XgActionMove::XgActionMove(float dx, float dy)
{
	this->dx = dx;
	this->dy = dy;
	this->dz = 0.0;
}


XgActionMove::~XgActionMove()
{
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgActionMove::update(float deltaTime, XgTransform &transform)
{
	transform.move(dx * deltaTime, dy * deltaTime, dz * deltaTime);
}
