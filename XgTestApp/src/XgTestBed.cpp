#include "XgTestBed.h"

#include "XgObjectFactory.h"
#include "XgObject.h"
#include "XgTrackerCircle.h"
#include "XgLightTrack.h"
#include "XgTrackerPosition.h"
#include "XgTrackerWalkAround.h"
#include "XgActionRoll.h"
#include "XgLightPosition.h"
#include "XgActionSpin.h"
#include "XgActionMove.h"
#include "XgEventFrames.h"
#include "XgActionSpeed.h"
#include "XgActionNegDirection.h"
#include "XgEventGoto.h"

string WALL_IMAGE = "wall.jpg";
string SUNSET_IMAGE = "sunset.jpg";
string STRIPES_IMAGE = "stripes.jpg";
string GRASS_IMAGE = "grass.jpg";
string WHITE_IMAGE = "white.jpg";
string NUKEM_IMAGE = "nukem.jpg";
string BLUE_IMAGE = "blue.jpg";
string CONTAINER_IMAGE = "container.jpg";
string PENGUIN_IMAGE = "penguin.jpg";

XgTestBed::XgTestBed()
{
}

XgTestBed::~XgTestBed()
{
}

XgScene *XgTestBed::spinningSphere()
{
	// (1) Instantiate Object Factor
	//------------------------------
	XgObjectFactory objectFactory;

	// (2) Create sphere object and start spinning action
	//---------------------------------------------------
	XgObject *sphere = objectFactory.sphere(GRASS_IMAGE);
	sphere->add(new XgActionSpin(0.0f, 0.02f, 0.0f));

	// (3) Position light source
	//--------------------------
	XgLight *light = new XgLightPosition(0.0, 10.0, 0.0);

	// (4) Postion view point
	//-----------------------
	XgTracker *tracker = new XgTrackerPosition(0.0, 0.0, 7.0);

	// (5) Create a scene objects and establish light and view
	//--------------------------------------------------------
	XgScene *scene = new XgScene();
	scene->add(sphere);
	scene->add(tracker);
	scene->add(light);

	// (6) Return the scene object to the caller
	//------------------------------------------
	return(scene);
}

XgScene *XgTestBed::displayNineSpheres()
{
	// Contain the pathnames of the textures
	//--------------------------------------
	string images[] = { 
		WALL_IMAGE, SUNSET_IMAGE, STRIPES_IMAGE,
		GRASS_IMAGE, WHITE_IMAGE, NUKEM_IMAGE,
		BLUE_IMAGE, CONTAINER_IMAGE, PENGUIN_IMAGE
	};

	// Define the static light source
	//-------------------------------
	XgLight *light = new XgLightPosition(0.0, 20.0, 0.0);

	// Define the static camera position
	//----------------------------------
	XgTracker *tracker = new XgTrackerWalkAround(0.1f);

	// Create the object factory
	//--------------------------
	XgObjectFactory objectFactory;

	// Create the scene object
	//------------------------
	XgScene *scene = new XgScene();
	scene->add(light);
	scene->add(tracker);

	float delta = 3.0;
	int image = 0;

	// Create the spheres and add them to the scene
	//---------------------------------------------
	for (float x = -delta; x <= delta; x += delta) {
		for (float y = -delta; y <= delta; y += delta) {
			XgObject *sphere = objectFactory.sphere(images[image++]);
			sphere->move(x, y, 0.0);
			scene->add(sphere);
		}
	}

	return(scene);
}

XgScene *XgTestBed::testRectangle01()
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

	scene->add(sphereLeft);
	scene->add(sphereCenter);
	scene->add(sphereRight);
	scene->add(floor);

	scene->add(new XgTrackerWalkAround(0.1f));
	//scene->add(new XgTrackCircle(7.0f));

	return(scene);
}

/*****************************************************************************
spinningFloor() -
*****************************************************************************/
XgScene *XgTestBed::backAndForth()
{
	const string STATE_FLIP = "FLIP";
	const string STATE_MOVE = "MOVE";

	float cameraHeight = 3.0f;
	float centerDistance = 7.0f;
	float moveSpeed = 0.01f;

	// (1) Instantiate object factory
	//-------------------------------
	XgObjectFactory objectFactory;

	// (2) Create the floor, scale it and define its position
	//-------------------------------------------------------
	XgObject *floor = objectFactory.rectangle(BLUE_IMAGE);
	floor->move(0.0, -1.0, 0.0);
	floor->scale(2.0);

	// (3) Define the behavior of the sphere
	//--------------------------------------
	XgState *flipState = new XgState(STATE_FLIP);
	flipState->add(new XgActionNegDirection());
	flipState->add(new XgEventGoto(STATE_MOVE));

	XgState *moveState = new XgState(STATE_MOVE);
	moveState->add(new XgActionSpeed(moveSpeed));
	moveState->add(new XgEventFrames(STATE_FLIP, 180));

	XgFramework *framework = new XgFramework();
	framework->add(flipState);
	framework->add(moveState);

	// (4) Create the sphere, set it spinning and apply its behavior
	//--------------------------------------------------------------
	XgObject *sphere = objectFactory.sphere(WALL_IMAGE);
	sphere->add(new XgActionSpin(0.005f, 0.005f, 0.001f));
	sphere->move(-1.0, 0.0, 0.0);
	sphere->add(framework);

	XgTracker *tracker = new XgTrackerPosition(0.0, 15.0, 5.0);
	//XgTracker *tracker = new XgTrackerWalkAround(0.1f);

	XgScene *scene = new XgScene();
	scene->add(sphere);
	scene->add(floor);
	scene->add(tracker);
	scene->add(new XgLightTrack());

	return(scene);
}

XgScene *XgTestBed::spinningFloor()
{
	float cameraHeight = 3.0f;
	float centerDistance = 7.0f;
	float floorPosition = -1.0f;

	XgObjectFactory objectFactory;

	XgObject *floor = objectFactory.rectangle(WALL_IMAGE);
	floor->move(0.0, floorPosition, 0.0);

	XgObject *sphere = objectFactory.sphere(STRIPES_IMAGE);
	//sphere->add(new XgActionSpin(0.0f, 0.0f, 0.05f));
	sphere->add(new XgActionMove(0.0f, 0.0f, 0.03f));

	XgScene *scene = new XgScene();

	scene->add(floor);
	scene->add(sphere);

	//scene->addCamera(new XgTrackerCircle(centerDistance, cameraHeight));
	scene->add(new XgTrackerWalkAround(0.01f));
	//scene->add(new XgTrackerPosition(5.0, 5.0, 5.0));
	scene->add(new XgLightTrack());

	return(scene);
}

XgScene *XgTestBed::rollingBall() 
{
	float cameraHeight = 5.0f;
	float centerDistance = 10.0f;
	float floorPosition = -1.0f;
	float spherePosition = -2.0;

	XgObjectFactory objectFactory;

	XgObject *sphere = objectFactory.sphere(STRIPES_IMAGE);
	//sphere->move(spherePosition, 0.0, 0.0);
	//sphere->add(new XgActionRoll());

	//XgObject *floor = objectFactory.rectangle(WALL_IMAGE);
	XgObject *floor = objectFactory.terrain(WALL_IMAGE, 300, 50.0, 2.0);
	floor->move(0.0, floorPosition, 0.0);

	// Add objects to the active screen
	//---------------------------------
	XgScene *scene = new XgScene();
	scene->add(floor);
	//scene->add(sphere);

	// Camera Source Tracking
	//-----------------------
	//scene->add(new XgTrackerCircle(centerDistance, cameraHeight));
	scene->add(new XgTrackerPosition(5.0, 5.0, 5.0));
	//scene->add(new XgTrackerWalkAround(0.01f));

	// Light Source Tracking
	//----------------------
	scene->add(new XgLightPosition(0.0, 10.0, 0.0));

	return(scene);

}

XgScene *XgTestBed::terrain()
{
	XgObjectFactory objectFactory;

	XgObject *terrainObject = objectFactory.terrain(WHITE_IMAGE, 25, 15.0, 3.0);
	terrainObject->move(0.0, -2.0f, 0.0);

	// Camera Source Tracking
	//-----------------------
	XgTrackerCircle *trackerCircle = new XgTrackerCircle();
	trackerCircle->setDistance(10.0);
	trackerCircle->setHeight(5.0);

	// Light Source Tracking
	//----------------------
	//scene->add(new XgRailPosition(0.0, 10.0, 0.0));

	XgScene *scene = new XgScene();
	scene->add(terrainObject);
	scene->add(trackerCircle);
	//scene->addCamera(new XgTrackerWalkAround(0.01f));

	return(scene);

}
