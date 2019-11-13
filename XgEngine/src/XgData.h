#pragma once

#include "XgObjectInfo.h"

struct XgFacePoint {
	XgFacePoint(int v, int t, int n) {
		vertex = v;
		texture = t;
		normal = n;
	};

	int vertex;
	int texture;
	int normal;
};

class XgData
{
public:
	XgData(XgObjectInfo &objectInfo);
	virtual ~XgData();

public:
	void createData();
	void remove();
	void displayObject();

	void loadObj(string pathName);
	void loadObj(string pathName, GLfloat r, GLfloat g, GLfloat b);

private:
	unsigned int vbo, vao, ebo;
	unsigned int *indices;
	XgVertex *vertices;
	int nIndices;
	int nFaces;
	int nVertices;
};

