#pragma once
#include "XgData.h"
class XgObjectMesh :
	public XgData
{
public:
	XgObjectMesh(string objectFormatFile);
	virtual ~XgObjectMesh();

public:
	virtual void dataFormat();
	virtual void draw();
	virtual void deAllocate();

};

