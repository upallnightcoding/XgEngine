#include "XgObjectTerrain.h"

#include <glm/gtc/noise.hpp>

XgObjectTerrain::XgObjectTerrain(int vertexCount, float size)
{
	this->vertexCount = vertexCount;
	this->size = size;
	this->nFaces = 0;

	AMPLITUDE = 70.0;
	seed = 100;

	srand(seed);

	generateVertex();
}

XgObjectTerrain::~XgObjectTerrain()
{
	delete vertices;
	delete indices;
}

void XgObjectTerrain::generateVertex()
{
	cout << "Rand: " << generateHeight(1.0, 1.0) << endl;
	cout << "Rand: " << generateHeight(1.0, 1.0) << endl;
	cout << "Rand: " << generateHeight(1.11, 1.0) << endl;

	int vertexPointer = 0;

	nVertices = vertexCount * vertexCount;
	vertices = new XgVertex[nVertices];
	
	for (float tx = 0.0; tx < vertexCount; tx++) {
		for (float ty = 0.0; ty < vertexCount; ty++) {
			float x = (float) (((ty / ((float) vertexCount - 1)) * size) - size / 2.0);
			float y = generateHeight(tx, ty);
			float z = (float) (((tx / ((float) vertexCount - 1)) * size) - size / 2.0);

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

float XgObjectTerrain::generateHeight(float x, float z)
{
	return(makeNoise(x, z) * AMPLITUDE);
}

float XgObjectTerrain::makeNoise(float x, float z)
{
	srand(x * 23456 + z * 76565 + seed);
	float value = rand() / RAND_MAX;
	return(value);
}

