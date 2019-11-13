#include "XgActionRoll.h"

#include "Xg.h"

XgActionRoll::XgActionRoll()
{
	firstRoll = true;
	speed = 0.03f;
	radius = 1.0f;
	direction = normalize(vec3(0.56, 0.0, -.78));
	turnAngle = 0.0;
	theta = 0.0;
}


XgActionRoll::~XgActionRoll()
{
}

/*****************************************************************************
render()
*****************************************************************************/
void XgActionRoll::update(double deltaTime, XgTransform &transform)
{
	if (firstRoll) {
		firstRoll = false;
		lastPosition = transform.getPosition();

		// Determine the turn angle of the rolling sphere
		//-----------------------------------------------
		turnAngle = acos(dot(vec3(1.0, 0.0, 0.0), direction));

		// Adjust the angle for the odd quadrant
		//--------------------------------------
		if ((direction.x < 0.0) && (direction.z < 0.0)) {
			turnAngle += XgConstant::PIE / 2;
		}

		if ((direction.x >= 0.0) && (direction.z < 0.0)) {
			turnAngle -= XgConstant::PIE / 2;
		}

		// Turn the sphere
		//----------------
		transform.turn(0.0, -turnAngle, 0.0);
	} else {
		// Calculate the distance the object has moved & move the object
		//--------------------------------------------------------------
		float dist = (float)(deltaTime * speed);

		// Calculate the z-rotation of the object based on distance
		//---------------------------------------------------------
		theta = dist / radius;
		transform.turn(0.0, 0.0, -theta);
		
		// Calculate the new position of the object based on direction vector
		//-------------------------------------------------------------------
		float dx = direction.x * dist;
		float dy = direction.y * dist;
		float dz = direction.z * dist;

		// Calculate the actual new position and last position
		//----------------------------------------------------
		vec3 newPosition = lastPosition + vec3(dx, dy, dz);
		transform.position(newPosition);
		lastPosition = newPosition;
	}
}
