#include "XgTrackerWalkAround.h"

#include "XgKeyboardEvent.h"

XgTrackerWalkAround::XgTrackerWalkAround(float cameraSpeed)
{
	this->cameraSpeed = cameraSpeed;

	this->cameraPos = vec3(0.0f, 0.0f, 3.0f);
	this->cameraFront = vec3(0.0f, 0.0f, -1.0f);
	this->cameraUp = vec3(0.0f, 1.0f, 0.0f);

	this->firstMouse = true;
}

XgTrackerWalkAround::~XgTrackerWalkAround()
{
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgTrackerWalkAround::update(XgRenderContext *context)
{
	updateCameraPositionWithMouse();

	updateCameraZoom(context);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		cameraPos += cameraSpeed * cameraFront;
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		cameraPos -= cameraSpeed * cameraFront;
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		cameraPos -= normalize(cross(cameraFront, cameraUp)) * cameraSpeed;
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		cameraPos += normalize(cross(cameraFront, cameraUp)) * cameraSpeed;
	}

	context->cameraTelemetry()->set(cameraPos, cameraPos + cameraFront);
}

/*****************************************************************************
updateCameraZoom()
*****************************************************************************/
void XgTrackerWalkAround::updateCameraZoom(XgRenderContext *context)
{
	double xOffSet = XgKeyboardEvent::getInstance()->xOffset();
	double yOffSet = XgKeyboardEvent::getInstance()->yOffSet();

	context->screenSize()->updateFov((float) -yOffSet);

	XgKeyboardEvent::getInstance()->zeroOffSet();
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgTrackerWalkAround::updateCameraPositionWithMouse()
{
	double xpos = XgKeyboardEvent::getInstance()->mouseXpos();
	double ypos = XgKeyboardEvent::getInstance()->mouseYpos();

	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	double xoffset = xpos - lastX;
	double yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	double sensitivity = 0.5;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f) {
		pitch = 89.0f;
	}	

	if (pitch < -89.0f) {
		pitch = -89.0f;
	}

	glm::vec3 front;
	front.x = (float) (cos(glm::radians(yaw)) * cos(glm::radians(pitch)));
	front.y = (float) (sin(glm::radians(pitch)));
	front.z = (float) (sin(glm::radians(yaw)) * cos(glm::radians(pitch)));

	cameraFront = glm::normalize(front);
}
