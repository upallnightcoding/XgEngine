#include <iostream>

#include "XgEngine.h"
#include "XgObjectFactory.h"
#include "XgActionGlow.h"
#include "XgActionSpin.h"
#include "XgTrackerCircle.h"
#include "XgTrackerPosition.h"
#include "XgTrackerWalkAround.h"

#include "XgTestBed.h"

using namespace std;

int main() 
{
	// (1) Define the engine and attributes
	//-------------------------------------
	XgEngine engine(1000, 600);

	// (2) Create scene object
	//------------------------
	XgScene *scene = XgTestBed::backAndForth();

	// (3) Load the scene into the engine
	//-----------------------------------
	engine.add(scene);

	// (4) Start the engine animation
	//-------------------------------
	engine.startAnimation();

	cin.get();
}

