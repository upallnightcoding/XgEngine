#include "XgCamera.h"



XgCamera::XgCamera()
{
	eye = vec3(0.0, 10.0, 0.0);
	center = vec3(0.0, 0.0, 0.0);
	up = vec3(0.0, 1.0, 0.0);
}

XgCamera::~XgCamera()
{
}

/******************************************************************************
add() -
******************************************************************************/
void XgCamera::add(XgTracker *track)
{
	tracking.push_back(track);
}

/******************************************************************************
create() -
******************************************************************************/
void XgCamera::create(GLFWwindow* window)
{
	for (auto tracker : tracking) {
		tracker->set(window);
	}
}

/******************************************************************************
getView() - Returns the view matrix, based on the eye, center and up vector
position.
******************************************************************************/
mat4 XgCamera::getView()
{
	return(lookAt(eye, center, up));
}

/******************************************************************************
getViewPosition() - Returns the current position of the camera.
******************************************************************************/
vec3 XgCamera::getPosition()
{
	return(eye);
}

/******************************************************************************
setViewPosition() - Sets the camera position
******************************************************************************/
void XgCamera::setPosition(float x, float y, float z)
{
	eye.x = x;
	eye.y = y;
	eye.z = z;
}

/******************************************************************************
update() - Updates the camera eye, center and up vector based on the virtual
function of the track object.  The "update" function executes each track
object.  Order of the track objects is based on the a first-in-first-out
processing rule.
******************************************************************************/
void XgCamera::update()
{
	for (auto track : tracking) {
		track->update(eye, center, up);
	}
}
