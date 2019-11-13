#include "XgObject.h"

XgObject::XgObject(XgObjectInfo &objectInfo)
	: XgData(objectInfo)
{
	shader = new XgShader(objectInfo.shaderName);
	texture = new XgTexture(objectInfo.textureFile);
	behavior = new XgBehavior();
}

XgObject::~XgObject()
{
	delete shader;
	delete texture;
	delete behavior;
}

/*****************************************************************************
render() -
*****************************************************************************/
void XgObject::render(XgLight &light, XgCamera &camera)
{
	shader->use(camera, light, transform);

	texture->render();

	displayObject();
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgObject::update(double deltaTime)
{
	behavior->update(deltaTime, transform);
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgObject::add(XgAction *action) 
{
	behavior->add(action);
}

/*****************************************************************************
create() -
*****************************************************************************/
void XgObject::create()
{
	createData();

	shader->create();

	texture->create();
}


