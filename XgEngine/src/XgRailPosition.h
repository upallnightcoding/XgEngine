#pragma once
#include "XgRail.h"


class XgRailPosition :
	public XgRail
{
public:
	XgRailPosition(float x, float y, float z);
	virtual ~XgRailPosition();

public:
	void update(vec3 &position, vec3 &colour);

private:
	float x;
	float y;
	float z;
};

