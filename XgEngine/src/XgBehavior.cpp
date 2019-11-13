#include "XgBehavior.h"



XgBehavior::XgBehavior()
{
}


XgBehavior::~XgBehavior()
{
}

void XgBehavior::add(XgAction *action)
{
	if (action != NULL) {
		behaviorList.push_back(action);
	}
}

void XgBehavior::update(double deltaTime, XgTransform &transform)
{
	for (auto action : behaviorList) {
		action->update(deltaTime, transform);
	}
}
