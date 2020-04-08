#include "XgObject.h"

#include "XgObjectMesh.h"

XgObject::XgObject(XgObjectInfo &objectInfo)
{
	texture = new XgObjectTexture(objectInfo.textureFile);
	localBehavior = new XgBehavior();
	data = new XgObjectMesh(objectInfo.objectFormatFile);
	framework = NULL;
}

XgObject::~XgObject()
{
	if (texture != NULL) {
		delete texture;
	}

	if (localBehavior != NULL) {
		delete localBehavior;
	}

	if (data != NULL) {
		delete data;
	}

	if (framework != NULL) {
		delete framework;
	}
}

/*****************************************************************************
render() -
*****************************************************************************/
void XgObject::render(XgShader *shader, XgRenderMode mode)
{
	//shader->uniform(XgConstant::U_OBJECT_COLOR, transform.getColour());
	//shader->uniform(XgConstant::U_OBJECT_TRANSFORM, transform.getTransformMatrix());
	shader->uniform("model", transform.getTransformMatrix());

	if (mode == XgRenderMode::OBJECT) {
		texture->render();
	}

	data->draw(mode);
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgObject::update(float deltaTime)
{
	if (framework != NULL) {
		XgBehavior *behavior = framework->update();

		if (behavior != NULL) {
			behavior->update(deltaTime, transform);
		}
	}

	localBehavior->update(deltaTime, transform);
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgObject::add(XgAction *action) 
{
	localBehavior->add(action);
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgObject::add(XgFramework *framework)
{
	this->framework = framework;
}

/*****************************************************************************
create() -
*****************************************************************************/
void XgObject::create()
{
	data->dataFormat();

	texture->create();
}


