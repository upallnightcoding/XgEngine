#pragma once

#include "Xg.h"

#include "XgScreenSize.h"
#include "XgCameraTelemetry.h"

class XgRenderContext
{
public:
	XgRenderContext();
	virtual ~XgRenderContext();

public:
	void cameraTelemetry(XgCameraTelemetry *cameraTelemetry);
	XgCameraTelemetry *cameraTelemetry();

	void screenSize(XgScreenSize *screenSize);
	XgScreenSize *screenSize();

private:
	XgScreenSize *pScreenSize;
	XgCameraTelemetry *pCameraTelemetry;
};

inline void XgRenderContext::screenSize(XgScreenSize *screenSize)
{
	pScreenSize = screenSize;
}

inline XgScreenSize *XgRenderContext::screenSize()
{
	return(pScreenSize);
}

inline void XgRenderContext::cameraTelemetry(XgCameraTelemetry *cameraTelemetry)
{
	pCameraTelemetry = cameraTelemetry;
}

inline XgCameraTelemetry *XgRenderContext::cameraTelemetry()
{
	return(pCameraTelemetry);
}


