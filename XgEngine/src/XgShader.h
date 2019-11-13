#pragma once

#include "Xg.h"
#include "XgTransform.h"
#include "XgCamera.h"
#include "XgLight.h"

class XgShader
{
public:
	XgShader(string pathName);
	virtual ~XgShader();

public:
	void use(XgCamera &camera, XgLight &light, XgTransform &transform);
	void create();
	string readShaderFile(const string pathname);

private:
	void setProjection(float fov, int screenWidth, int screenHeight, float near, float far);
	int compile(const char *source, GLenum shaderType);
	void link(int vertexShader, int fragmentShader);

	void uniform(string name, vec3 value);
	void uniform(string name, mat4 value);

private:
	int shaderProgram;
	//int viewLocation;
	//int projectionLocation;
	string pathName;
};

