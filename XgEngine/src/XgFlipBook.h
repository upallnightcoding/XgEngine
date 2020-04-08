#pragma once

#include "XgSprite.h"

class XgFlipBook
{
public:
	XgFlipBook();
	virtual ~XgFlipBook();

public:
	void add(XgSprite *sprite);
	void animate();
	void create();

private:
	vector<XgSprite*> flipBookList;
	int nSprites;
	int currentSprite;
	int speed;
	int fpsCounter;
};
