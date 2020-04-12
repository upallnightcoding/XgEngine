#include "XgPaper.h"



XgPaper::XgPaper()
{
	
}


XgPaper::~XgPaper()
{
	
}

/*****************************************************************************
animate()
*****************************************************************************/
void XgPaper::animate(XgShader *shader)
{
	// Animate all sprites that are on the paper
	//------------------------------------------
	for (auto sprite : spriteList) {
		sprite->draw(shader);
	}

	// Animate all flipbooks that are on the paper
	//--------------------------------------------
	for (auto flipBook : flipBookList) {
		flipBook->animate(shader);
	}

	// Animate all entities that are on the paper
	//-------------------------------------------
	for (auto entity : entityList) {
		entity->animate(shader);
	}
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgPaper::update(float deltaTime)
{
	// Animate all entities that are on the paper
	//-------------------------------------------
	for (auto entity : entityList) {
		entity->update(deltaTime);
	}

	for (auto sprite : spriteList) {
		sprite->update(deltaTime);
	}
}

/*****************************************************************************
create() -
*****************************************************************************/
void XgPaper::create(GLFWwindow* window)
{
	for (auto sprite : spriteList) {
		sprite->create();
	}

	for (auto flipBook : flipBookList) {
		flipBook->create();
	}

	for (auto entity : entityList) {
		entity->create();
	}

}