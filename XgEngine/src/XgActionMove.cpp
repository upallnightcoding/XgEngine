#include "XgActionMove.h"



XgActionMove::XgActionMove(float dx, float dy, float dz)
{
	this->dx = dx;
	this->dy = dy;
	this->dz = dz;
}


XgActionMove::~XgActionMove()
{
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgActionMove::update(float deltaTime, XgTransform &transform)
{
	transform.move(dx, dy, dz);
}
