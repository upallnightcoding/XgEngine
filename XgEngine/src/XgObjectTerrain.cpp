#include "XgObjectTerrain.h"
#include "XgPerlin.h"

XgObjectTerrain::XgObjectTerrain(int vertexCount, float size, float smooth)
{
	this->vertexCount = vertexCount;
	this->size = size;
	this->nFaces = 0;
	this->smooth = smooth;

	generateVertex();
}

XgObjectTerrain::~XgObjectTerrain()
{
	delete vertices;
	delete indices;
}

/*****************************************************************************
generateVertex() -
*****************************************************************************/
void XgObjectTerrain::generateVertex()
{
	XgPerlin perlin(237);
	int vertexPointer = 0;

	nVertices = vertexCount * vertexCount;
	vertices = new XgVertex[nVertices];
	
	for (float tx = 0.0; tx < vertexCount; tx++) {
		for (float ty = 0.0; ty < vertexCount; ty++) {
			float x = ((tx / vertexCount) * size) - (size / 2.0);
			float z = ((ty / vertexCount) * size) - (size / 2.0);
			float y = 5 * perlin.noise(x/smooth, 0.0, z/smooth);

			float u = 0.0;
			float v = 1.0;
			float w = 0.0;

			float s = ty / ((float) vertexCount - 1);
			float t = tx / ((float) vertexCount - 1);

			vertices[vertexPointer].point = vec3(x, y, z);
			vertices[vertexPointer].normal = vec3(u, v, w);
			vertices[vertexPointer].texture = vec2(s, t);

			vertexPointer++;
		}
	}

	int indicesPointer = 0;

	nIndices = 6 * (vertexCount - 1) * (vertexCount - 1);
	indices = new unsigned int[nIndices];

	for (int gz = 0; gz < vertexCount - 1; gz++) {
		for (int gx = 0; gx < vertexCount - 1; gx++) {
			int topLeft = (gz * vertexCount) + gx;
			int topRight = topLeft + 1;
			int bottomLeft = ((gz + 1) * vertexCount) + gx;
			int bottomRight = bottomLeft + 1;

			indices[indicesPointer++] = topLeft;
			indices[indicesPointer++] = bottomLeft;
			indices[indicesPointer++] = topRight;
			indices[indicesPointer++] = topRight;
			indices[indicesPointer++] = bottomLeft;
			indices[indicesPointer++] = bottomRight;

			nFaces += 2;
		}
	}

	nFaces *= 3;
}

