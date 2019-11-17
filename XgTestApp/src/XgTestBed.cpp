#include "XgTestBed.h"

#include "XgObjectFactory.h"
#include "XgObject.h"
#include "XgTrackerCircle.h"
#include "XgRailTrack.h"
#include "XgTrackerPosition.h"
#include "XgTrackerWalkAround.h"
#include "XgActionRoll.h"
#include "XgRailPosition.h"

const string WALL_IMAGE = "wall.jpg";
const string SUNSET_IMAGE = "sunset.jpg";
const string STRIPES_IMAGE = "stripes.jpg";
const string GRASS_IMAGE = "grass.jpg";
const string WHITE_IMAGE = "white.jpg";

XgTestBed::XgTestBed()
{
}


XgTestBed::~XgTestBed()
{
}

XgScene *XgTestBed::spinningFloor()
{
	float cameraHeight = 3.0f;
	float centerDistance = 7.0f;
	float floorPosition = -1.0f;

	XgObjectFactory objectFactory;

	XgObject *floor = objectFactory.rectangle(WALL_IMAGE);
	floor->move(0.0, floorPosition, 0.0);

	XgScene *scene = new XgScene();

	scene->addObject(floor);

	//scene->add(new XgTrackerCircle(centerDistance, cameraHeight));
	scene->addCamera(new XgTrackerPosition(5.0, 5.0, 5.0));
	scene->add(new XgRailTrack());

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
	scene->addObject(floor);
	//scene->add(sphere);

	// Camera Source Tracking
	//-----------------------
	scene->addCamera(new XgTrackerCircle(centerDistance, cameraHeight));
	//scene->add(new XgTrackerPosition(5.0, 5.0, 5.0));
	//scene->add(new XgTrackerWalkAround(0.01f));

	// Light Source Tracking
	//----------------------
	scene->add(new XgRailPosition(0.0, 10.0, 0.0));

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
	scene->addObject(terrainObject);
	scene->addCamera(trackerCircle);
	//scene->addCamera(new XgTrackerWalkAround(0.01f));

	return(scene);

}
