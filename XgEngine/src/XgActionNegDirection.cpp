#include "XgActionNegDirection.h"



XgActionNegDirection::XgActionNegDirection()
{
}


XgActionNegDirection::~XgActionNegDirection()
{
}

void XgActionNegDirection::update(float deltaTime, XgTransform &transform)
{
	transform.flipDirection();
}
