#pragma once

#include "Xg.h"

#include "XgSprite.h"
#include "XgFlipBook.h"
#include "XgShader.h"

class XgPaper
{
public:
	XgPaper();
	virtual ~XgPaper();

public:
	void create();
	void add(XgSprite *sprite);
	void add(XgFlipBook *flipBook);
	void animate();
	void update(float deltaTime);

private:
	vector<XgSprite*> spriteList;
	vector<XgFlipBook*> flipBookList;

	XgShader *shader;
};

inline void XgPaper::add(XgFlipBook *flipBook)
{
	if (flipBook != NULL) {
		flipBookList.push_back(flipBook);
	}
}

/*****************************************************************************
add()
*****************************************************************************/
inline void XgPaper::add(XgSprite *sprite)
{
	if (sprite != NULL) {
		spriteList.push_back(sprite);
	}
}

/*****************************************************************************
update() -
*****************************************************************************/
inline void XgPaper::update(float deltaTime)
{
	for (auto sprite : spriteList) {
		sprite->update(deltaTime);
	}
}