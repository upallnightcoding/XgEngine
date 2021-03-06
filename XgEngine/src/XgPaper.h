#pragma once

#include "Xg.h"

#include "XgSprite.h"
#include "XgFlipBook.h"
#include "XgShader.h"
#include "XgEntity.h"

class XgPaper
{
public:
	XgPaper();
	virtual ~XgPaper();

public:
	void create(GLFWwindow* window);

	void add(XgSprite *sprite);
	void add(XgFlipBook *flipBook);
	void add(XgEntity *entity);

	void animate(XgShader *shader);
	void update(float deltaTime);

private:
	vector<XgSprite*> spriteList;
	vector<XgFlipBook*> flipBookList;
	vector<XgEntity*> entityList;
};

/*****************************************************************************
add()
*****************************************************************************/
inline void XgPaper::add(XgEntity *entity)
{
	if (entity != NULL) {
		entityList.push_back(entity);
	}
}

/*****************************************************************************
add()
*****************************************************************************/
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

