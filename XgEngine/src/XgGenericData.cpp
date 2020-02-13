#include "XgGenericData.h"



XgGenericData::XgGenericData(XgObjectInfo &objectInfo) : XgData(objectInfo)
{
}


XgGenericData::~XgGenericData()
{
}

void XgGenericData::remove()
{
	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);
}
