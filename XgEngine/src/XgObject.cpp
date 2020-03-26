#include "XgObject.h"

#include "XgDataObjectTexture.h"

XgObject::XgObject(XgObjectInfo &objectInfo)
{
	shader = new XgShader(objectInfo.shaderName);
	texture = new XgTexture(objectInfo.textureFile);
	localBehavior = new XgBehavior();
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
void XgObject::render(XgScreenSize &screenSize, XgLighting &light, XgCamera &camera)
{
	shader->use(screenSize, camera, light, transform);

	texture->render();

	data->drawObject();
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

	shader->create();

	texture->create();
}


