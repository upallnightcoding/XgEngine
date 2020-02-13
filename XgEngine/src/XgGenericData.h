#pragma once
#include "XgData.h"

#include "Xg.h"

class XgGenericData :
	public XgData
{
public:
	XgGenericData(XgObjectInfo &objectInfo);
	virtual ~XgGenericData();

	virtual void remove();
};

