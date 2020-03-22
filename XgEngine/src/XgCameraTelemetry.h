#pragma once

#include "Xg.h"

class XgCameraTelemetry
{
public:
	XgCameraTelemetry();
	virtual ~XgCameraTelemetry() {}

public:
	mat4 getLookAt();

	vec3 eye();

	void set(float x, float y, float z);

	void set(vec3 eye, vec3 center);

private:
	vec3 pEye;
	vec3 pCenter;
	vec3 pUp;
};

/*****************************************************************************
set() - Sets the "eye" and "center" camera position and viewing direction.
*****************************************************************************/
inline void XgCameraTelemetry::set(vec3 eye, vec3 center)
{
	pEye = eye;
	pCenter = center;
}

/*****************************************************************************
getView() - Return the "lookAt" position of the camera telemetry.
*****************************************************************************/
inline mat4 XgCameraTelemetry::getLookAt()
{
	return(lookAt(pEye, pCenter, pUp));
}

/*****************************************************************************
eye() - Return the eye position of the camera.
*****************************************************************************/
inline vec3 XgCameraTelemetry::eye()
{
	return(pEye);
}

/*****************************************************************************
set() - Set the "eye" position of the camera.  The "eye" position is 
defeined by the x, y, z components.
*****************************************************************************/
inline void XgCameraTelemetry::set(float x, float y, float z)
{
	pEye.x = x;
	pEye.y = y;
	pEye.z = z;
}

