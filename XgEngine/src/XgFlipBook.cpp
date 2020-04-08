#include "XgFlipBook.h"



XgFlipBook::XgFlipBook()
{
}


XgFlipBook::~XgFlipBook()
{
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgFlipBook::add(XgSprite *sprite)
{
	if (sprite != NULL) {
		flipBookList.push_back(sprite);
	}
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgFlipBook::create()
{
	for (auto sprite : flipBookList) {
		sprite->create();
	}

	nSprites = flipBookList.size();
	currentSprite = 0;

	speed = 60 / 15;
	fpsCounter = 0;
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgFlipBook::animate()
{
	//if (fpsCounter == 0) {
		flipBookList.at(currentSprite)->draw();

		currentSprite = ++currentSprite % nSprites;
	//}

	//fpsCounter = ++fpsCounter % 60;
}