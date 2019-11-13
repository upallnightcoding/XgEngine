#include "XgRailTrack.h"

float x = -4.0;

XgRailTrack::XgRailTrack()
{
}


XgRailTrack::~XgRailTrack()
{
}

void XgRailTrack::update(vec3 &position, vec3 &colour)
{
	position = vec3(0.0, 5.0, 0.0);
	x += 0.02;
	colour = vec3(1.0);
}
