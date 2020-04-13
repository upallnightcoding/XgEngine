#pragma once

/*****************************************************************************
classs XgKeyboardEvent
*****************************************************************************/

class XgKeyboardEvent
{
public:
	static XgKeyboardEvent *instance;

	// Private constructor
	XgKeyboardEvent()
	{
		pMouseXpos = pMouseYpos = 0.0;
		pXoffset = pYoffset = 0.0;

		key = scancode = action = mods = 0;
	}

public:
	static XgKeyboardEvent *getInstance();

	void setMousePosition(double xpos, double ypos);
	void setScrollPosition(double xoffset, double yoffset);

	void zeroOffSet();

	double mouseXpos();
	double mouseYpos();

	double xOffset();
	double yOffSet();

	void setKey(int key, int scancode, int action, int mods);
	void getKey(int &key, int &scancode, int &action, int &mods);
	bool isKeyPressed(int targetKey);

private:
	double pMouseXpos;
	double pMouseYpos;
	double pXoffset;
	double pYoffset;

	int key;
	int scancode;
	int action;
	int mods;
};

