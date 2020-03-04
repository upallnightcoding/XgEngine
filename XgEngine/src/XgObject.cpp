#include "XgObject.h"

#include "XgDataObjectTexture.h"

XgObject::XgObject(XgObjectInfo &objectInfo)
{
	shader = new XgShader(objectInfo.shaderName);
	texture = new XgTexture(objectInfo.textureFile);
	behavior = new XgBehavior();
	data = new XgDataObjectTexture(objectInfo.objectFormatFile);
	framework = NULL;
}

XgObject::~XgObject()
{
	if (shader != NULL) {
		delete shader;
	}

	if (texture != NULL) {
		delete texture;
	}

	if (behavior != NULL) {
		delete behavior;
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
void XgObject::render(XgLight &light, XgCamera &camera)
{
	shader->use(camera, light, transform);

	texture->render();

	data->drawObject();
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgObject::update(float deltaTime)
{
	if (framework != NULL) {
		XgBehavior *newBehavior = framework->update();

		if (newBehavior != NULL) {
			behavior = newBehavior;
		}
	}

	if (behavior != NULL) {
		behavior->update(deltaTime, transform);
	}
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgObject::add(XgAction *action) 
{
	behavior->add(action);
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

	shader->create();

	texture->create();
}


