#include "XgEntity.h"



XgEntity::XgEntity()
{
	flipBook = 0;
}


XgEntity::~XgEntity()
{
}

/*****************************************************************************
update()
*****************************************************************************/
void XgEntity::update(float deltaTime)
{
	if (framework != NULL) {
		XgBehavior *behavior = framework->update();

		if ((behavior != NULL) && (flipBook != -1)) {
			XgTransform *transform = flipBookList.at(flipBook)->getTransform();
			behavior->update(deltaTime, *transform);
		}
	}

	if (flipBook != -1) {
		flipBookList.at(flipBook)->update(deltaTime);
	}
}