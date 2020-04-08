#include "XgObjectMesh.h"



XgObjectMesh::XgObjectMesh(string objectFormatFile) : XgData()
{
	string directory =
		XgConstant::WORK_SPACE + XgConstant::MODEL_DIRECTORY;

	//loadObj(directory + objectFormatFile);

	loadTinyObj(directory + objectFormatFile);
}

XgObjectMesh::~XgObjectMesh()
{
	
}

/*****************************************************************************
formatData() - Creates the object vao
*****************************************************************************/
void XgObjectMesh::dataFormat()
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
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, nIndices * sizeof(uint32_t), indices, GL_STATIC_DRAW);

	// Position Attribute
	//-------------------
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Normal Attribute
	//-----------------
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// Texture Coordinatge Attribute
	//------------------------------
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	// Color Coordinate Attribute
	//---------------------------
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(8 * sizeof(float)));
	glEnableVertexAttribArray(3);

	glBindVertexArray(0);
}

/*****************************************************************************
drawObject() - Creates the object vao
*****************************************************************************/
void XgObjectMesh::draw(XgRenderMode mode)
{
	glBindVertexArray(vao);

	glEnableVertexAttribArray(0);

	if (mode == XgRenderMode::OBJECT) {
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);
		glEnableVertexAttribArray(3);
	}

	glDrawElements(GL_TRIANGLES, nIndices, GL_UNSIGNED_INT, 0);
	// glDrawElements(GL_TRIANGLES, 40, GL_UNSIGNED_INT, 0);
	// glBindVertexArray(0); // no need to unbind it every time 

	glDisableVertexAttribArray(0);

	if (mode == -XgRenderMode::OBJECT) {
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);
		glDisableVertexAttribArray(3);
	}
}

/*****************************************************************************
deAllocateData() - Creates the object vao
*****************************************************************************/
void XgObjectMesh::deAllocate()
{
	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);
}
