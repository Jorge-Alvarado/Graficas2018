#include "Shader.h"
#include "InputFile.h"

/***********************************************************************
Materia:		Gráficas Computacionales
Fecha:			21 de Agosto del 2017
Autor:			A01167344 Alumno Jorge luis Alvarado Durán
************************************************************************/

Shader::Shader() {
	_shaderHandle = 0;
}

Shader::~Shader() {
	glDeleteShader(_shaderHandle);
}

void Shader::CreateShader(std::string path, GLenum type) {
	if (_shaderHandle != 0) {
		glDeleteShader(_shaderHandle);
	}
	InputFile ifile;
	_shaderHandle = glCreateShader(type);
	ifile.Read(path);
	std::string source = ifile.GetContents();
	const GLchar* sourceC = (const GLchar*)source.c_str();
	glShaderSource(_shaderHandle, 1, &sourceC, nullptr);
	glCompileShader(_shaderHandle);

}

GLuint Shader::GetHandle() {
	return _shaderHandle;
}
