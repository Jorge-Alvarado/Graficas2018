#pragma once


#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>

/***********************************************************************
Materia:		Gr�ficas Computacionales
Fecha:			21 de Agosto del 2017
Autor:			A01167344 Alumno Jorge luis Alvarado Dur�n
************************************************************************/

class Shader {
private:
	GLuint _shaderHandle = 0;

public:
	Shader();
	~Shader();
	void CreateShader(std::string path, GLenum type);
	GLuint GetHandle();
};