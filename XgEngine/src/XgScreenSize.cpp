#include "XgScreenSize.h"



XgScreenSize::XgScreenSize(int width, int height)
{
	this->pWidth = width;
	this->pHeight = height;
	this->pNear = 0.1f;
	this->pFar = 100.0f;
	this->pFov = 45.0f;
}


XgScreenSize::~XgScreenSize()
{
}
