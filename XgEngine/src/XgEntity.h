#pragma once

#include "Xg.h"
#include "XgFlipBook.h"
#include "XgFramework.h"

class XgEntity
{
public:
	XgEntity();
	virtual ~XgEntity();

public:
	void animate(XgShader *shader);
	void create();
	void update(float deltaTime);

	void add(XgFramework *framework);
	void add(XgFlipBook *flipBook);

private:
	vector<XgFlipBook*> flipBookList;
	XgFramework *framework;
	int flipBook;
};

/*****************************************************************************
add() -
*****************************************************************************/
inline void XgEntity::add(XgFramework *framework)
{
	this->framework = framework;
}

/*****************************************************************************
create() -
*****************************************************************************/
inline void XgEntity::create()
{
	for (auto flipBook : flipBookList) {
		flipBook->create();
	}
}

/*****************************************************************************
add() - 
*****************************************************************************/
inline void XgEntity::add(XgFlipBook *flipBook)
{
	if (flipBook != NULL) {
		flipBookList.push_back(flipBook);
	}
}

/*****************************************************************************
animate()
*****************************************************************************/
inline void XgEntity::animate(XgShader *shader)
{
	if (flipBook != -1) {
		flipBookList.at(flipBook)->animate(shader);
	}
}



