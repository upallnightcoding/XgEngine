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

const string WALL_IMAGE = "wall.jpg";
const string SUNSET_IMAGE = "sunset.jpg";
const string STRIPES_IMAGE = "stripes.jpg";
const string GRASS_IMAGE = "grass.jpg";
const string WHITE_IMAGE = "white.jpg";
const string NUKEM_IMAGE = "nukem.jpg";
const string BLUE_IMAGE = "blue.jpg";

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
	float floorPosition = -1.0f;
	float moveSpeed = 0.01f;

	XgObjectFactory objectFactory;

	//XgObject *floor = objectFactory.rectangle(WALL_IMAGE);
	XgObject *floor = objectFactory.cube(WALL_IMAGE);
	floor->move(0.0, floorPosition, 0.0);
	floor->scale(2.0, 1.0, 2.0);

	XgState *flipState = new XgState(STATE_FLIP);
	flipState->add(new XgActionNegDirection());
	flipState->add(new XgEventGoto(STATE_MOVE));

	XgState *moveState = new XgState(STATE_MOVE);
	moveState->add(new XgActionSpeed(moveSpeed));
	moveState->add(new XgEventFrames(STATE_FLIP, 180));

	XgFramework *framework = new XgFramework();
	framework->add(flipState);
	framework->add(moveState);

	//XgObject *sphere = objectFactory.monkey(WALL_IMAGE);
	XgObject *sphere = objectFactory.sphere(WALL_IMAGE);
	sphere->add(new XgActionSpin(0.005f, 0.005f, 0.001f));
	sphere->add(framework);

	XgScene *scene = new XgScene();
	scene->add(floor);
	scene->add(sphere);

	//scene->add(new XgTrackerCircle(centerDistance, cameraHeight));
	scene->add(new XgTrackerPosition(5.0, 5.0, 5.0));
	//scene->add(new XgTrackerWalkAround(moveSpeed));
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
	scene->lineMode();
	scene->add(terrainObject);
	scene->add(trackerCircle);
	//scene->addCamera(new XgTrackerWalkAround(0.01f));

	return(scene);

}
