#pragma once

#include <GL/freeglut.h>
#include <iostream>
#include <string>

class Textura2D {
public:
	Textura2D();
	~Textura2D();
	void LoadTexture(std::string path);
	void Bind();
	void Unbind();
private:
	GLuint _textureId;
};