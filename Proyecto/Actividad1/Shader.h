/***************************
Materia:Gr�ficas Computacionales Gr�ficas
Fecha: 02/10/2017
Autor: A01167344 Jorge Luis Alvarado Dur�n
*****************************/
#pragma once
#include <string>
#include <vector>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

class Shader {
private:
	GLuint _shaderHandle;

public:
	Shader();
	~Shader();
	void CreateShader(std::string path, GLenum type);
	GLuint GetHandle();
};