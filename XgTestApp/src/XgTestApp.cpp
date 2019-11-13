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

XgScene *testRectangle01() 
{	
	XgObjectFactory objectFactory; 

	// TODO Create a resource directory via the explore view
	XgObject *sphereLeft = objectFactory.sphere("penguin.jpg");
	sphereLeft->move(-3.0, 0.0, 0.0);

	XgObject *sphereCenter = objectFactory.sphere("sunset.jpg");
	sphereCenter->move(0.0, 0.0, 0.0);
	sphereCenter->add(new XgActionSpin(0.0f, 0.05f, 0.0f));

	XgObject *sphereRight = objectFactory.sphere("tiles01.jpg");
	sphereRight->move(3.0, 0.0, 0.0);

	XgObject *floor = objectFactory.rectangle("nukem.jpg");
	floor->move(0.0, -1.0, 0.0);
	floor->turn(radians(-90.0f), 0.0f, 0.0f);

	XgScene *scene = new XgScene();

	scene->addObject(sphereLeft);
	scene->addObject(sphereCenter);
	scene->addObject(sphereRight);
	scene->addObject(floor);

	scene->addCamera(new XgTrackerWalkAround(0.1f));
	//scene->add(new XgTrackCircle(7.0f));

	return(scene);
}


int main() 
{
	cout << "Xg Test App" << endl;

	XgEngine engine(800, 600);

	engine.add(XgTestBed::terrain());

	engine.startRenderingWindow();

	cin.get();
}

