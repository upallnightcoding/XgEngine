#pragma once

#include "XgSprite.h"

/*****************************************************************************
XgFlipBook
*****************************************************************************/
class XgFlipBook
{
public:
	XgFlipBook();
	virtual ~XgFlipBook();

public:
	void add(XgSprite *sprite);
	void add(XgAction *action);
	void add(XgBehavior *localBehavior);

	void animate(XgShader *shader);
	void create();
	void update(float deltaTime);

	XgTransform *getTransform();

private:
	XgBehavior *localBehavior;

	// Translate, rotate and scale transformation
	XgTransform transform;

	// List of animation images
	vector<XgSprite*> flipBookList;

	// Number of images in the flipbook
	int nSprites;

	// Current image being displayed
	int currentSprite;

	// Current speed of animation
	float speed;
	float speedBuffer;
};

inline XgTransform *XgFlipBook::getTransform()
{
	return(&transform);
}
