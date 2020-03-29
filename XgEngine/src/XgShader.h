#pragma once

#include "Xg.h"
#include "XgTransform.h"
#include "XgCamera.h"
#include "XgLighting.h"
#include "XgScreenSize.h"

/*****************************************************************************
class XgShader
*****************************************************************************/
class XgShader
{
public:
	XgShader(string pathName);
	virtual ~XgShader();

public:
	void use();
	void use(mat4 lightSpaceMatrix);
	void use(XgScreenSize &screenSize, XgCamera &camera, XgLighting &light, XgTransform &transform);
	void create();

	void uniform(string name, vec3 value);
	void uniform(string name, vec4 value);
	void uniform(string name, mat4 value);
	
private:
	string readShaderFile(const string pathname);
	int compile(const char *source, GLenum shaderType);
	void link(int vertexShader, int fragmentShader);

private:
	int shaderProgram;
	string pathName;
};

