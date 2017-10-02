#include "ShaderProgram.h"
#include "Shader.h"
#include <memory>

/***********************************************************************
Materia:		Gráficas Computacionales
Fecha:			21 de Agosto del 2017
Autor:			A01167344 Alumno Jorge luis Alvarado Durán
************************************************************************/

ShaderProgram::ShaderProgram() {
	_programHandle = 0;
}

ShaderProgram::~ShaderProgram() {
	DeleteProgram();
}

void ShaderProgram::CreateProgram() {

	_programHandle = glCreateProgram();
}

void ShaderProgram::AttachShader(std::string path, GLenum type) {
	std::unique_ptr<Shader> shader(new Shader);
	shader->CreateShader(path, type);
	_attachedShaders.push_back(std::move(shader));

}

void ShaderProgram::LinkProgram() {
	for (auto &sh : _attachedShaders) {
		glAttachShader(_programHandle, sh->GetHandle());
	}
	glLinkProgram(_programHandle);
	DeleteAndDetachShaders();
}

void ShaderProgram::Activate() {
	glUseProgram(_programHandle);
}

void ShaderProgram::Deactivate() {
	glUseProgram(0);
}

void ShaderProgram::SetAttribute(GLuint locationIndex, std::string name) {
	glBindAttribLocation(_programHandle, locationIndex, (const GLchar*)name.c_str());

}

void ShaderProgram::SetUniformf(std::string name, float value) {
	GLint uniformLocation = glGetUniformLocation(_programHandle, (const GLchar*)name.c_str());
	glUniform1f(uniformLocation, value);
}

void ShaderProgram::SetUniformf(std::string name, float x, float y) {

	GLint uniformLocation = glGetUniformLocation(_programHandle, (const GLchar*)name.c_str());
	glUniform2f(uniformLocation, x, y);
}

void ShaderProgram::SetUniformf(std::string name, float x, float y, float z) {
	GLint uniformLocation = glGetUniformLocation(_programHandle, (const GLchar*)name.c_str());
	glUniform3f(uniformLocation, x, y, z);
}

void ShaderProgram::SetUniformf(std::string name, float x, float y, float z, float w) {
	GLint uniformLocation = glGetUniformLocation(_programHandle, (const GLchar*)name.c_str());
	glUniform4f(uniformLocation, x, y, z, w);
}

void ShaderProgram::DeleteAndDetachShaders() {

	for (auto &sh : _attachedShaders) {
		glDetachShader(_programHandle, sh->GetHandle());
		glDeleteShader(sh->GetHandle());
	}
	_attachedShaders.erase(_attachedShaders.begin(), _attachedShaders.end()); //
}

void ShaderProgram::DeleteProgram() {
	DeleteAndDetachShaders();
	glDeleteProgram(_programHandle);
}
