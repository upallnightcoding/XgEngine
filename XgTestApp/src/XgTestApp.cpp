#include <iostream>

#include "XgEngine.h"
#include "XgTestBed.h"

#include "XgPixel.h"

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

	XgFlipBook *flipBook = new XgFlipBook();
	flipBook->add(new XgSprite("Attack__000.png"));
	flipBook->add(new XgSprite("Attack__001.png"));
	flipBook->add(new XgSprite("Attack__002.png"));
	flipBook->add(new XgSprite("Attack__003.png"));
	flipBook->add(new XgSprite("Attack__004.png"));
	flipBook->add(new XgSprite("Attack__005.png"));
	flipBook->add(new XgSprite("Attack__006.png"));
	flipBook->add(new XgSprite("Attack__007.png"));
	flipBook->add(new XgSprite("Attack__008.png"));
	flipBook->add(new XgSprite("Attack__009.png"));

	paper->add(flipBook);

	pixel.add(paper);

	pixel.startAnimation();

	cin.get();
}
