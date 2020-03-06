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
	XgData();
	virtual ~XgData();

public:
	unsigned int vbo, vao, ebo;

public:
	virtual void dataFormat() = 0;
	virtual void drawObject() = 0;
	virtual void deAllocate() = 0;

	void loadObj(string pathName);
	void loadObj(string pathName, GLfloat r, GLfloat g, GLfloat b);
	void loadTinyObj(string pathname);

protected:
	uint32_t *indices;
	XgVertex *vertices;
	
	int nIndices;
	int nFaces;
	int nVertices;

private:
	vector<XgVertex> verticesData;
	vector<uint32_t> indicesData;
};

