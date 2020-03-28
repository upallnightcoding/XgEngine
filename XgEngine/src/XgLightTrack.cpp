#include "XgLightTrack.h"

float x = -4.0;

XgLightTrack::XgLightTrack()
{
}


XgLightTrack::~XgLightTrack()
{
}

void XgLightTrack::update(vec3 &position, vec3 &colour)
{
	position = vec3(0.0, 5.0, 0.0);
	x += 0.02;
	colour = vec3(1.0);
}
