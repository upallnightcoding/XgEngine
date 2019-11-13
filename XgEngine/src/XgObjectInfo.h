#pragma once

#include "Xg.h"
#include "XgVertex.h"

enum class XgObjectInfoType {
	OBJECT_FILE_AND_SHADER,
	VERTEX_AND_SHADER
};

struct XgObjectInfo {
	XgObjectInfoType type;

	string shaderName;
	string objectFormatFile;
	string textureFile;

	int nIndices;
	unsigned int *indices;

	int nVertices;
	XgVertex *vertices;

	int nFaces;
};
