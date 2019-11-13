#pragma once
class XgKeyboardEvent
{
public:
	XgKeyboardEvent();
	virtual ~XgKeyboardEvent();

public:
	void setMousePosition(double xpos, double ypos);
	void setScrollPosition(double xoffset, double yoffset);

	double getXpos();
	double getYpos();

	float getFov();

private:
	double mouseXpos;
	double mouseYpos;

	double xoffset;
	double yoffset;

	double fov;
};

