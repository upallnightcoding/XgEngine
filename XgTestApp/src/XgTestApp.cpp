#include <iostream>

#include "XgEngine.h"
#include "XgTestBed.h"

#include "XgPixel.h"
#include "XgActionMove.h"

int xxmain() 
{
	// (1) Define the engine and attributes
	//-------------------------------------
	XgEngine engine(1000, 600);

	// (2) Create scene object
	//------------------------
	XgScene *scene = XgTestBed::displayNineSpheres();

	// (3) Load the scene into the engine
	//-----------------------------------
	engine.add(scene);

	// (4) Start the engine animation
	//-------------------------------
	engine.startAnimation();

	cin.get();

	return(0);
}

int main()
{
	XgPixel pixel(800, 600);

	XgPaper *paper = new XgPaper();

	XgFlipBook *attackFlipBook = new XgFlipBook();
	attackFlipBook->add(new XgSprite("Attack__000.png"));
	attackFlipBook->add(new XgSprite("Attack__001.png"));
	attackFlipBook->add(new XgSprite("Attack__002.png"));
	attackFlipBook->add(new XgSprite("Attack__003.png"));
	attackFlipBook->add(new XgSprite("Attack__004.png"));
	attackFlipBook->add(new XgSprite("Attack__005.png"));
	attackFlipBook->add(new XgSprite("Attack__006.png"));
	attackFlipBook->add(new XgSprite("Attack__007.png"));
	attackFlipBook->add(new XgSprite("Attack__008.png"));
	attackFlipBook->add(new XgSprite("Attack__009.png"));

	attackFlipBook->add(new XgActionMove(0.01, 0.0, 0.0));

	XgEntity *entity = new XgEntity();
	entity->add(attackFlipBook);

	paper->add(entity);

	pixel.add(paper);

	pixel.startAnimation();

	cin.get();
}
