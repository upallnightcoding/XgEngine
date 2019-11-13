#pragma once

#include "XgVertex.h"

class XgObjectTerrain
{
public:
	XgObjectTerrain(int vertexCount, float size);
	virtual ~XgObjectTerrain();

public:
	unsigned int *getIndices();
	XgVertex *getVertices();
	int getnIndices();
	int getnVertices();
	int getnFaces();

private:
	void generateVertex();
	float generateHeight(float x, float z);
	float makeNoise(float x, float z);

private:
	unsigned int *indices;
	XgVertex *vertices;
	int nIndices;
	int nVertices;
	int nFaces;

	int vertexCount;
	float size;

	float AMPLITUDE;
	unsigned int seed;
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

