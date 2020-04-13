#include "XgEventKeyboard.h"
#include "XgKeyboardEvent.h"


XgEventKeyboard::XgEventKeyboard(string nextState, int targetKey) 
	: XgEvent(nextState)
{
	this->targetKey = targetKey;
	this->keyHasAlreadyBeenPressed = false;
}


XgEventKeyboard::~XgEventKeyboard()
{
}

/*****************************************************************************
hasOccured() -
*****************************************************************************/
bool XgEventKeyboard::hasOccured()
{
	bool occured = false;

	bool keyPressed = XgKeyboardEvent::getInstance()->isKeyPressed(targetKey);

	if (keyPressed && !keyHasAlreadyBeenPressed) {
		occured = true;
		keyHasAlreadyBeenPressed = true;
	}
	else if (keyPressed) {
		occured = false;
		keyHasAlreadyBeenPressed = true;
	}
	else {
		occured = false;
		keyHasAlreadyBeenPressed = false;
	}

	return(occured);
}
