#include "XgPaper.h"



XgPaper::XgPaper()
{
	shader = new XgShader("sprite.shader");
}


XgPaper::~XgPaper()
{
	delete shader;
}

/*****************************************************************************
animate()
*****************************************************************************/
void XgPaper::animate()
{
	// Animate all sprites that are on the paper
	//------------------------------------------
	for (auto sprite : spriteList) {
		sprite->draw();
	}

	// Animate all flipbooks that are on the paper
	//--------------------------------------------
	for (auto flipBook : flipBookList) {
		flipBook->animate();
	}
}

/*****************************************************************************
create() -
*****************************************************************************/
void XgPaper::create()
{
	for (auto sprite : spriteList) {
		sprite->create();
	}

	for (auto flipBook : flipBookList) {
		flipBook->create();
	}

	shader->create();

	shader->use();
}