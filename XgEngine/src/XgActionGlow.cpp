#include "XgActionGlow.h"



XgActionGlow::XgActionGlow()
{
}


XgActionGlow::~XgActionGlow()
{
}

void XgActionGlow::update(XgTransform &transform)
{
	vec4 colour = transform.getColour();
	 
	float timeValue = (float)glfwGetTime();

	colour.g = sin(timeValue) / 2.0f + 0.5f;

	transform.paint(colour);
}