#pragma once
#include "XgRail.h"
class XgRailTrack :
	public XgRail
{
public:
	XgRailTrack();
	virtual ~XgRailTrack();

public:
	virtual void update(vec3 &position, vec3 &colour);
};

