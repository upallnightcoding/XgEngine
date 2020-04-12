#include "XgFlipBook.h"



XgFlipBook::XgFlipBook()
{
	localBehavior = new XgBehavior();
}


XgFlipBook::~XgFlipBook()
{
}

/*****************************************************************************
add() -  Add local behavior to the entity.  If the behavior is null, it is 
not added to the entity.
*****************************************************************************/
void XgFlipBook::add(XgBehavior *localBehavior)
{
	if (localBehavior != NULL) {
		this->localBehavior = localBehavior;
	}
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgFlipBook::add(XgAction *action)
{
	if (action != NULL) {
		localBehavior->add(action);
	}
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
create() -
*****************************************************************************/
void XgFlipBook::create()
{
	for (auto sprite : flipBookList) {
		sprite->create(false);
	}

	nSprites = flipBookList.size();
	currentSprite = 0;

	speed = 60 / 30;
	speedBuffer = 0.0;
}

/*****************************************************************************
animate() - Executes the animation of a flipbook.  The transformation of the
object is set first via a uniform and the current sprite of the flipbook is
drawn with the current shader.
*****************************************************************************/
void XgFlipBook::animate(XgShader *shader)
{
	shader->uniform("u_Transform", transform.getTransformMatrix());

	flipBookList.at(currentSprite)->draw(shader);
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgFlipBook::update(float deltaTime)
{
	localBehavior->update(deltaTime, transform);

	speedBuffer += deltaTime;

	if (speedBuffer > speed) {
		currentSprite = ++currentSprite % nSprites;
		speedBuffer = 0.0;
	}
}