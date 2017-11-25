#include "Textura2D.h"
#include <IL/il.h>

Textura2D::Textura2D()
{
	_textureId = 0;
}

Textura2D::~Textura2D()
{
	glDeleteTextures(1, &_textureId);
}

void Textura2D::LoadTexture(std::string path)
{
	if (_textureId) {
		glDeleteTextures(1, &_textureId);
	}
	ILuint imageID;
	ilGenImages(1, &imageID);
	ilBindImage(imageID);
	ilLoadImage(path.c_str());
	glGenTextures(1, &_textureId);
	//
	Bind();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_FORMAT),ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT),0, ilGetInteger(IL_IMAGE_FORMAT), ilGetInteger(IL_IMAGE_TYPE),ilGetData());
	Unbind();
	ilBindImage(0);
	ilDeleteImages(1, &imageID);
}

void Textura2D::Bind()
{

	glBindTexture(GL_TEXTURE_2D, _textureId);
}

void Textura2D::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
