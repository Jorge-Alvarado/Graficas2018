#pragma once


#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include "Shader.h"
#include <memory>

/***********************************************************************
Materia:		Gráficas Computacionales
Fecha:			21 de Agosto del 2017
Autor:			A01167344 Alumno Jorge luis Alvarado Durán
************************************************************************/


class ShaderProgram {
private:
	GLuint _programHandle = 0;
	std::vector<std::unique_ptr<Shader>> _attachedShaders;
	void DeleteAndDetachShaders();
	void DeleteProgram();

public:
	ShaderProgram();
	~ShaderProgram();
	void CreateProgram();
	void AttachShader(std::string path, GLenum type);
	void LinkProgram();
	void Activate();
	void Deactivate();
	void SetAttribute(GLuint locationIndex, std::string name);
	void SetUniformf(std::string name, float value);
	void SetUniformf(std::string name, float x, float y);
	void SetUniformf(std::string name, float x, float y, float z);
	void SetUniformf(std::string name, float x, float y, float z, float w);

};
