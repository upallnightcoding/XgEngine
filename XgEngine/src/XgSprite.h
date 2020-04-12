#pragma once

#include "Xg.h"
#include "XgPoint.h"
#include "XgShader.h"
#include "XgBehavior.h"

class XgSprite
{
public:
	XgSprite(string texturePath);
	virtual ~XgSprite();

public:
	void draw(XgShader *shader);
	void create(bool updateTransform);
	void create();
	void add(XgAction *action);
	void update(float deltaTime);

private:
	void dataFormat();
	void loadTexture();
	void cleanUp();

private:
	bool updateTransform;

	XgTransform transform;

	XgBehavior *localBehavior;

	string imagePath;

	unsigned int vbo, vao, ebo;

	unsigned int texture;
	
	float vertices[32] = {
		// positions          // colors           // texture coords
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
	};

	unsigned int indices[6] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};
};



