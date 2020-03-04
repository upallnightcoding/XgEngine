#pragma once
#include "XgData.h"
class XgDataObjectTexture :
	public XgData
{
public:
	XgDataObjectTexture(string objectFormatFile);
	virtual ~XgDataObjectTexture();

public:
	virtual void dataFormat();
	virtual void drawObject();
	virtual void deAllocate();

};

