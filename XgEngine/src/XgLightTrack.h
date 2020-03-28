#pragma once
#include "XgLight.h"
class XgLightTrack :
	public XgLight
{
public:
	XgLightTrack();
	virtual ~XgLightTrack();

public:
	virtual void update(vec3 &position, vec3 &colour);
};

