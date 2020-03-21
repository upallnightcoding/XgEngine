#pragma once

#include "Xg.h"

class XgTransform
{
public:
	XgTransform();
	virtual ~XgTransform();

	mat4 getTransformMatrix();

	vec3 getPosition();
	vec4 getColour();

	void move(float x, float y, float z);
	void move(float speed, float deltaTime);

	void flipDirection();

	void turn(float x, float y, float z);
	void scale(float x, float y, float z);
	void scale(float value);
	void position(float x, float y, float z);
	void position(vec3 point);
	void paint(vec4 &colourObj);

	void sety(float value);

private:
	vec3 translateObj;
	vec3 rotateObj;
	vec3 scaleObj;
	vec4 colourObj;

	vec3 direction;
};

