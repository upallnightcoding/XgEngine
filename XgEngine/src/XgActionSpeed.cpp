#include "XgActionSpeed.h"



XgActionSpeed::XgActionSpeed(float speed)
{
	this->speed = speed;
}


XgActionSpeed::~XgActionSpeed()
{
}

/******************************************************************************
update() -
******************************************************************************/
void XgActionSpeed::update(float deltaTime, XgTransform &transform)
{
	transform.move(speed, deltaTime);
}
