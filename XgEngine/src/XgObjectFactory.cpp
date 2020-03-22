#include "XgObjectFactory.h"

#include "XgObjectInfo.h"
#include "XgObjectTerrain.h"

// Vertex data for two triangles, this will form a rectangle
// ---------------------------------------------------------
XgVertex RECTANGLE_VERTICES[] = {
	{ { 0.5f,  0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 1.0f} },	// [0] - top right
	{ { 0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f} }, // [1] - bottom right
	{ {-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f} }, // [2] - bottom left
	{ {-0.5f,  0.5f, 0.0f}, {1.0f, 1.0f, 0.0f}, {0.0f, 1.0f} }  // [3] - top left 
};

unsigned int RECTANGLE_INDICES[] = {  // note that we start from 0!
	0, 1, 3,  // First Triangle
	1, 2, 3   // Second Triangle
};

float TRIANGLE_VERTICES[] = {
	// positions         // colors
	 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
	 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
};

unsigned int TRIANGLE_INDICES[] = {
	0, 1, 2
};

XgObjectFactory::XgObjectFactory()
{
}


XgObjectFactory::~XgObjectFactory()
{
}

XgObject *XgObjectFactory::terrain(string textureFile, int nPoints, float size, float smooth)
{
	XgObjectTerrain *terrain = new XgObjectTerrain(nPoints, size, smooth);

	XgObjectInfo objectInfo;
	objectInfo.type = XgObjectInfoType::VERTEX_AND_SHADER;
	objectInfo.shaderName = "LowPolyTerrain.shader";
	objectInfo.nIndices = terrain->getnIndices();
	objectInfo.indices = terrain->getIndices();
	objectInfo.nVertices = terrain->getnVertices();
	objectInfo.vertices = terrain->getVertices();
	objectInfo.nFaces = terrain->getnFaces();
	objectInfo.textureFile = textureFile;

	return(new XgObject(objectInfo));
}

XgObject *XgObjectFactory::sphere(string textureFile)
{
	XgObjectInfo objectInfo;
	objectInfo.type = XgObjectInfoType::OBJECT_FILE_AND_SHADER;
	objectInfo.shaderName = "GeneralVertext.shader";
	objectInfo.objectFormatFile = "sphere.obj";
	objectInfo.textureFile = textureFile;

	return(new XgObject(objectInfo));
}

XgObject *XgObjectFactory::monkey(string textureFile)
{
	XgObjectInfo objectInfo;
	objectInfo.type = XgObjectInfoType::OBJECT_FILE_AND_SHADER;
	objectInfo.shaderName = "GeneralVertext.shader";
	objectInfo.objectFormatFile = "monkey.obj";
	objectInfo.textureFile = textureFile;

	return(new XgObject(objectInfo));
}

XgObject *XgObjectFactory::cube(string textureFile)
{
	XgObjectInfo objectInfo;
	objectInfo.type = XgObjectInfoType::OBJECT_FILE_AND_SHADER;
	objectInfo.shaderName = "GeneralVertext.shader";
	objectInfo.objectFormatFile = "cube01.obj";
	objectInfo.textureFile = textureFile;

	return(new XgObject(objectInfo));
}

XgObject *XgObjectFactory::rectangle(string textureFile)
{
	XgObjectInfo objectInfo;
	objectInfo.type = XgObjectInfoType::OBJECT_FILE_AND_SHADER;
	objectInfo.shaderName = "GeneralVertext.shader";
	objectInfo.objectFormatFile = "rectangle.obj";
	objectInfo.textureFile = textureFile;

	return(new XgObject(objectInfo));
}

XgObject *XgObjectFactory::triangle(string textureFile)
{
	XgObjectInfo objectInfo;
	objectInfo.type = XgObjectInfoType::OBJECT_FILE_AND_SHADER;
	objectInfo.shaderName = "GeneralVertext.shader";
	objectInfo.nIndices = 3;
	objectInfo.indices = TRIANGLE_INDICES;
	objectInfo.nVertices = 3;
	//objectInfo.vertices = TRIANGLE_VERTICES;

	return(new XgObject(objectInfo));
}