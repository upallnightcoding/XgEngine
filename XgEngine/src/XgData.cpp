#include "XgData.h"

#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>

#include "Xg.h"

struct Vertex {
	glm::vec3 pos;
	glm::vec3 color;
	glm::vec2 texCoord;

	bool operator==(const Vertex& other) const {
		return pos == other.pos && color == other.color && texCoord == other.texCoord;
	}
};

namespace std {
	template<> struct hash<Vertex> {
		size_t operator()(Vertex const& vertex) const {
			return ((hash<glm::vec3>()(vertex.pos) ^ (hash<glm::vec3>()(vertex.color) << 1)) >> 1) ^ (hash<glm::vec2>()(vertex.texCoord) << 1);
		}
	};
}

XgData::XgData()
{
	
}

XgData::~XgData()
{
	
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

	vector<vec3> objPos;
	vector<vec3> objNormals;
	vector<vec2> objTexture;

	vector<XgFacePoint> allFacePoints;

	fopen_s(&file, pathName.c_str(), "r");

	while (res != EOF) {
		char lineHeader[128];

		res = fscanf_s(file, "%s", lineHeader, 128);

		if (res != EOF) {
			if (strcmp(lineHeader, "v") == 0) {
				GLfloat x, y, z;
				fscanf_s(file, "%f %f %f\n", &x, &y, &z);
				objPos.push_back(vec3(x, y, z));
			}

			if (strcmp(lineHeader, "vn") == 0) {
				GLfloat x, y, z;
				fscanf_s(file, "%f %f %f\n", &x, &y, &z);
				objNormals.push_back(vec3(x, y, z));
			}

			if (strcmp(lineHeader, "vt") == 0) {
				GLfloat s, t;
				fscanf_s(file, "%f %f\n", &s, &t);
				objTexture.push_back(vec2(s, t));
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
	nVertices = objPos.size();

	vertices = new XgVertex[nVertices];
	indices = new unsigned int[nFaces];

	//vertices.resize(nVertices);
	//indices.resize(nFaces);
	for (int i = 0; i < nFaces; i++) {
		int pointIndex = allFacePoints[i].vertex;
		vertices[pointIndex].point = objPos[pointIndex];
		vertices[pointIndex].normal = objNormals[allFacePoints[i].normal];
		vertices[pointIndex].texture = objTexture[allFacePoints[i].texture];

		indices[i] = pointIndex;
	}
}

void XgData::loadTinyObj(string pathname)
{
	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;
	std::string warn, err;

	if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, pathname.c_str())) {
		throw std::runtime_error(warn + err);
	}

	std::unordered_map<Vertex, uint32_t> uniqueVertices = {};

	for (const auto& shape : shapes) {
		for (const auto& index : shape.mesh.indices) {
			Vertex vertex = {};

			vertex.pos = {
				attrib.vertices[3 * index.vertex_index + 0],
				attrib.vertices[3 * index.vertex_index + 1],
				attrib.vertices[3 * index.vertex_index + 2]
			};

			vertex.texCoord = {
				attrib.texcoords[2 * index.texcoord_index + 0],
				1.0f - attrib.texcoords[2 * index.texcoord_index + 1]
			};

			vertex.color = { 1.0f, 1.0f, 1.0f };

			if (uniqueVertices.count(vertex) == 0) {
				//uniqueVertices[vertex] = static_cast<uint32_t>(vertices.size());
				//vertices.push_back(vertex);
			}

			//indices.push_back(uniqueVertices[vertex]);
		}
	}
}