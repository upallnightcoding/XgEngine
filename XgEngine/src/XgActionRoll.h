#pragma once
#include "XgAction.h"
class XgActionRoll :
	public XgAction
{
public:
	XgActionRoll();
	virtual ~XgActionRoll();

public:
	void update(float deltaTime, XgTransform &transform);

private:
	bool firstRoll;
	vec3 lastPosition;
	vec3 direction;
	float speed;
	float radius;

	float turnAngle;
	float theta;
};

