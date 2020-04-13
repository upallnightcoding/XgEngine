#include <iostream>

#include "XgEngine.h"
#include "XgTestBed.h"

#include "XgPixel.h"
#include "XgActionMove.h"
#include "XgEventKeyboard.h"
#include "XgEventGoto.h"
#include "XgActionNegDirection.h"
#include "XgActionSpin.h"

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
	string MOVE_STATE = "MOVE";
	string TURN_STATE = "TURN";

	XgState *moveState = new XgState(MOVE_STATE);
	moveState->add(new XgEventKeyboard(TURN_STATE, 'T'));
	moveState->add(new XgActionMove(0.001, 0.0));

	XgState *turnState = new XgState(TURN_STATE);
	turnState->add(new XgEventGoto(MOVE_STATE));
	turnState->add(new XgActionNegDirection());
	turnState->add(new XgActionSpin(0.0, 180.0, 0.0));

	XgFramework *framework = new XgFramework();
	framework->add(moveState);
	framework->add(turnState);

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

	XgEntity *entity = new XgEntity();
	entity->add(framework);
	entity->add(attackFlipBook);

	XgPaper *paper = new XgPaper();
	paper->add(entity);

	XgPixel pixel(800, 600);
	pixel.add(paper);
	pixel.startAnimation();

	cin.get();
}
