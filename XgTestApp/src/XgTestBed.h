#pragma once

#include "XgScene.h"

class XgTestBed
{
public:
	XgTestBed();
	~XgTestBed();

public:
	static XgScene *spinningFloor();
	static XgScene *rollingBall();
	static XgScene *terrain();
};

