#pragma once

#include <string>

using namespace std;

/*****************************************************************************
XgRenderMode - This enum sets the rending mode of the screen.
*****************************************************************************/
enum XgRenderMode
{
	SHADOW,	// Rendering the scene shadow from the lights POV
	OBJECT	// Rendering the scene from the POV of the lookAt()
};

/*****************************************************************************
XgConstant 
*****************************************************************************/
class XgConstant
{
public:
	static const char *U_PROJECT;

	static const char *U_CAMERA_VIEW;

	static const char *U_LIGHT_COLOR;
	static const char *U_LIGHT_POSITION;

	static const char *U_OBJECT_COLOR;
	static const char *U_OBJECT_TRANSFORM;

	static const char *U_CAMERA_POSITION;

	static const string WORK_SPACE;

	static const string SHADER_DIRECTORY;

	static const string IMAGE_DIRECTORY;

	static const string MODEL_DIRECTORY;

	static const string EMPTY_STRING;

	static const float PIE;
};

