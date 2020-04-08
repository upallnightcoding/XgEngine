#include "XgSprite.h"

//#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

XgSprite::XgSprite(string texturePath)
{
	this->imagePath =
		XgConstant::WORK_SPACE + XgConstant::IMAGE_DIRECTORY + texturePath;
}

XgSprite::~XgSprite()
{
	//delete shader;
}

void XgSprite::create()
{
	//shader = new XgShader("sprite.shader");

	//shader->create();

	dataFormat();

	loadTexture();
}

/*****************************************************************************
formatData() - Creates the object vao
*****************************************************************************/
void XgSprite::dataFormat()
{
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
}

/******************************************************************************
create() -
******************************************************************************/

void XgSprite::loadTexture()
{
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture); 

	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(true);

	// load image, create texture and generate mipmaps
	int width, height, nrChannels;
	unsigned char *data = stbi_load(imagePath.c_str(), &width, &height, &nrChannels, STBI_rgb_alpha);

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture:" << stbi_failure_reason() << std::endl;
	}

	stbi_image_free(data);
}

/******************************************************************************
create() -
******************************************************************************/
void XgSprite::draw()
{
	//shader->use();

	glBindTexture(GL_TEXTURE_2D, texture);

	glBindVertexArray(vao);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

/*****************************************************************************
update() -
*****************************************************************************/
void XgSprite::update(float deltaTime)
{
	localBehavior->update(deltaTime, transform);
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgSprite::add(XgAction *action)
{
	if (action != NULL) {
		localBehavior->add(action);
	}
}

/*****************************************************************************
add() -
*****************************************************************************/
void XgSprite::cleanUp()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);
}