#include "XgData.h"

#include "Xg.h"

XgData::XgData(XgObjectInfo &objectInfo)
{
	//this->nIndices = objectInfo.nIndices;
	//this->indices = objectInfo.indices;

	//this->nVertices = objectInfo.nVertices;
	//this->vertices = objectInfo.vertices;

	string objectFormatFile;

	switch (objectInfo.type) {
	case XgObjectInfoType::VERTEX_AND_SHADER:
		this->indices = objectInfo.indices;
		this->nIndices = objectInfo.nIndices;
		this->vertices = objectInfo.vertices;
		this->nVertices = objectInfo.nVertices;
		this->nFaces = objectInfo.nFaces;
		break;
	case XgObjectInfoType::OBJECT_FILE_AND_SHADER:
		objectFormatFile = XgConstant::WORK_SPACE + XgConstant::MODEL_DIRECTORY + objectInfo.objectFormatFile;
		loadObj(objectFormatFile);
		break;
	}
}

XgData::~XgData()
{
	if (vertices != NULL) {
		delete vertices;
		vertices = NULL;
	}

	if (indices != NULL) {
		delete indices;
		indices = NULL;
	 }
}

/*****************************************************************************
create() - Creates the object vao
*****************************************************************************/
void XgData::createData()
{
	// Create a vao, vbo and ebo buffers
	//----------------------------------
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	// Bind Vertex Array Object - Over rides any other VAO binding
	glBindVertexArray(vao);

	// Create VBO buffer - Calculate number of bytes from number of vertices
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, nVertices * sizeof(XgVertex), vertices, GL_STATIC_DRAW);

	// Create EBO buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, nIndices * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	//glEnableVertexAttribArray(0);

	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	//glEnableVertexAttribArray(1);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO 
	// as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void XgData::displayObject()
{
	glBindVertexArray(vao); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	glDrawElements(GL_TRIANGLES, nIndices, GL_UNSIGNED_INT, 0);
	//glDrawElements(GL_TRIANGLES, 40, GL_UNSIGNED_INT, 0);
	// glBindVertexArray(0); // no need to unbind it every time 
}

void XgData::remove()
{
	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);
}

/*****************************************************************************
loadObj() -
*****************************************************************************/
void XgData::loadObj(string pathName)
{
	loadObj(pathName, 1.0, 1.0, 1.0);
}

/*****************************************************************************
loadObj() -
*****************************************************************************/
void XgData::loadObj(string pathName, GLfloat r, GLfloat g, GLfloat b)
{
	FILE *file = NULL;
	int res = 0;
	long faceCount = 0;

	vector<vec3> vertPos;
	vector<vec3> vertNormals;
	vector<vec2> vertTexture;

	vector<XgFacePoint> allFacePoints;

	fopen_s(&file, pathName.c_str(), "r");

	while (res != EOF) {
		char lineHeader[128];

		res = fscanf_s(file, "%s", lineHeader, 128);

		if (res != EOF) {
			if (strcmp(lineHeader, "v") == 0) {
				GLfloat x, y, z;
				fscanf_s(file, "%f %f %f\n", &x, &y, &z);
				vertPos.push_back(vec3(x, y, z));
			}

			if (strcmp(lineHeader, "vn") == 0) {
				GLfloat x, y, z;
				fscanf_s(file, "%f %f %f\n", &x, &y, &z);
				vertNormals.push_back(vec3(x, y, z));
			}

			if (strcmp(lineHeader, "vt") == 0) {
				GLfloat s, t;
				fscanf_s(file, "%f %f\n", &s, &t);
				vertTexture.push_back(vec2(s, t));
			}

			if (strcmp(lineHeader, "f") == 0) {
				GLint i1, i2, i3;
				GLint u1, u2, u3;
				GLint n1, n2, n3;
				fscanf_s(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &i1, &u1, &n1, &i2, &u2, &n2, &i3, &u3, &n3);

				XgFacePoint facePoint1(--i1, --u1, --n1);
				XgFacePoint facePoint2(--i2, --u2, --n2);
				XgFacePoint facePoint3(--i3, --u3, --n3);

				allFacePoints.push_back(facePoint1);
				allFacePoints.push_back(facePoint2);
				allFacePoints.push_back(facePoint3);
			}
		}
	}

	nFaces = allFacePoints.size();
	nIndices = allFacePoints.size();
	nVertices = vertPos.size();

	vertices = new XgVertex[nVertices];
	indices = new unsigned int[nFaces];
	for (int i = 0; i < nFaces; i++) {
		int pointIndex = allFacePoints.at(i).vertex;
		vertices[pointIndex].point = vertPos.at(pointIndex);
		vertices[pointIndex].normal = vertNormals.at(allFacePoints.at(i).normal);
		vertices[pointIndex].texture = vertTexture.at(allFacePoints.at(i).texture);

		indices[i] = pointIndex;
	}
}

