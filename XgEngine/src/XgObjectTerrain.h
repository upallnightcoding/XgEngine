#pragma once

#include "XgVertex.h"

class XgObjectTerrain
{
public:
	XgObjectTerrain(int vertexCount, float size, float smooth);
	virtual ~XgObjectTerrain();

public:
	unsigned int *getIndices();
	XgVertex *getVertices();
	int getnIndices();
	int getnVertices();
	int getnFaces();

private:
	void generateVertex();

private:
	unsigned int *indices;
	XgVertex *vertices;
	int nIndices;
	int nVertices;
	int nFaces;

	int vertexCount;
	float size;
	float smooth;
};

inline int XgObjectTerrain::getnFaces()
{
	return(nFaces);
}

inline unsigned int *XgObjectTerrain::getIndices()
{
	return(indices);
}

inline XgVertex *XgObjectTerrain::getVertices()
{
	return(vertices);
}

inline int XgObjectTerrain::getnIndices()
{
	return(nIndices);
}

inline int XgObjectTerrain::getnVertices()
{
	return(nVertices);
}

