#include "XgTexture.h"

#include "Xg.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

XgTexture::XgTexture(string texturePath)
{
	this->texturePath = 
		XgConstant::WORK_SPACE + XgConstant::IMAGE_DIRECTORY + texturePath;
}


XgTexture::~XgTexture()
{
}

/******************************************************************************
render() -
******************************************************************************/
void XgTexture::render()
{
	glBindTexture(GL_TEXTURE_2D, texture);
}

/******************************************************************************
create() -
******************************************************************************/
void XgTexture::create()
{
	// Genertate a texture name
	glGenTextures(1, &texture);

	// Bind a named texture to a texturing target
	glBindTexture(GL_TEXTURE_2D, texture);

	// Set texture parameters wrapping parameters (as GL_REPEAT)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Set texture filtering parameters (as GL_LINEAR)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(true);

	// load image, create texture and generate mipmaps
	int width, height, nrChannels;

	// The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
	unsigned char *data = stbi_load(texturePath.c_str(), &width, &height, &nrChannels, 0);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "Failed to load texture" << std::endl;
	}

	stbi_image_free(data);

}