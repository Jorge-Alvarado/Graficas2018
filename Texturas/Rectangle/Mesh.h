#pragma once
#include <string>
#include <glm/glm.hpp>
#include <vector>
#include <GL/glew.h>
#include <GL/freeglut.h>

/********************************************
Materia:Gráficas Computacionales Gráficas
Fecha: 02/10/2017
Autor: A01167344 Jorge Luis Alvarado Durán
**********************************************/

class Mesh {
private:
	GLuint _vertexArrayObject;
	GLuint _positionsVertexBufferObject;
	GLuint _colorsVertexBufferObject;
	GLuint _normalVertexBufferObject;
	GLint _vertexCount;
	GLuint _indicesBufferObject;
	GLint _indicesCount;
	GLuint _texCoordsVertexBufferObject;

	void SetAttributeData(GLuint& buffer, const GLsizeiptr size, const void* data, GLenum usage, GLuint locationIndex, const GLint components);
	void SetTexCoordAttribute(std::vector<glm::vec2>texCoords, GLenum usage, GLuint locationIndex);

public:
	Mesh();
	~Mesh();
	void CreateMesh(GLint vertexCount);
	void Draw(GLenum primitive);
	void SetPositionAttribute(std::vector<glm::vec2> positions, GLenum usage, GLuint locationIndex);
	void SetPositionAttribute(std::vector<glm::vec3> positions, GLenum usage, GLuint locationIndex);
	void SetColorAttribute(std::vector<glm::vec3> colors, GLenum usage, GLuint locationIndex);
	void SetColorAttribute(std::vector<glm::vec4> colors, GLenum usage, GLuint locationIndex);
	void SetNormalAttribute(std::vector<glm::vec3> normal, GLenum usage, GLuint locationIndex);
	void SetIndices(std::vector <unsigned int> indices, GLenum usage);
};