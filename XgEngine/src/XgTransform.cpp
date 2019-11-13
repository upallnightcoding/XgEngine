#include "XgTransform.h"

XgTransform::XgTransform()
{
	translateObj = vec3(0.0f);
	rotateObj = vec3(0.0f);
	scaleObj = vec3(1.0);
	colourObj = vec4(0.0, 0.0, 0.0, 1.0);

}

XgTransform::~XgTransform()
{
}

/******************************************************************************
getTransformMatrix() - Create the transform matrix to manipulate the model
coordinates.  The model coordinates can be translated, rotated, and scaled.
This matrix is needed for the uniform calculation.
******************************************************************************/
mat4 XgTransform::getTransformMatrix()
{
	// Set the transform identity matrix
	//----------------------------------
	mat4 transform = mat4(1.0f);

	// Set the transform tranlation
	//-----------------------------
	transform = translate(transform, translateObj);

	// Set the transforma rotation (x, y z)
	//-------------------------------------
	transform = rotate(transform, rotateObj.x, vec3(1.0f, 0.0f, 0.0f));
	transform = rotate(transform, rotateObj.y, vec3(0.0f, 1.0f, 0.0f));
	transform = rotate(transform, rotateObj.z, vec3(0.0f, 0.0f, 1.0f));

	// Set the transform scale
	//------------------------
	transform = scale(transform, scaleObj);

	return(transform);
}

/******************************************************************************
set() -
******************************************************************************/
void XgTransform::sety(float value)
{
	translateObj.y = value;
}

/******************************************************************************
move() -
******************************************************************************/
void XgTransform::move(float x, float y, float z)
{
	translateObj.x += x;
	translateObj.y += y;
	translateObj.z += z;
}

/******************************************************************************
turn() -
******************************************************************************/

void XgTransform::turn(float x, float y, float z)
{
	rotateObj.x += x;
	rotateObj.y += y;
	rotateObj.z += z;
}

/******************************************************************************
position() -
******************************************************************************/
void XgTransform::position(vec3 point)
{
	position(point.x, point.y, point.z);
}

/******************************************************************************
position() -
******************************************************************************/
void XgTransform::position(float x, float y, float z)
{
	translateObj.x = x;
	translateObj.y = y;
	translateObj.z = z;
}

/******************************************************************************
size() -
******************************************************************************/
void XgTransform::size(float x, float y, float z)
{
	scaleObj.x = x;
	scaleObj.y = y;
	scaleObj.z = z;
}

/******************************************************************************
paint() -
******************************************************************************/
void XgTransform::paint(vec4 &colourObj)
{
	this->colourObj = colourObj;
}

/*****************************************************************************
size() - Return the scaled size of the current objeft with x, y, and z 
scaling values equal.
*****************************************************************************/
void XgTransform::size(float value)
{
	size(value, value, value);
}

/*****************************************************************************
getPosition() - Returns the model position of the current object.
*****************************************************************************/
vec3 XgTransform::getPosition()
{
	return(translateObj);
}

/*****************************************************************************
getColour() - Returns the current object color value.  This value is used to
determine the "uniform" color of the current object.
*****************************************************************************/
vec4 XgTransform::getColour()
{
	return(colourObj);
}