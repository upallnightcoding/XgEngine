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
	// Define the engine and attributes
	//---------------------------------
	XgEngine engine(1000, 600);

	// Load the scene into the engine
	//-------------------------------
	engine.add(XgTestBed::figure01());

	// Start the engine animation
	//---------------------------
	engine.startAnimation();
}

