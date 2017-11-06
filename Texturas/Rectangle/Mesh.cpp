/***************************
Materia:Gráficas Computacionales Gráficas
Fecha: 02/10/2017
Autor: A01374356 Garcia Roque Javier Antonio
*****************************/
#include "Mesh.h"


Mesh::Mesh() {
	_vertexArrayObject = 0;
	_positionsVertexBufferObject = 0;
	_colorsVertexBufferObject = 0;
	_normalVertexBufferObject = 0;
	_vertexCount = 0;
	_indicesBufferObject = 0;
	_indicesCount = 0;
}

Mesh::~Mesh() {
	glDeleteVertexArrays(1, &_vertexArrayObject);
	glDeleteBuffers(1, &_positionsVertexBufferObject);
	glDeleteBuffers(1, &_colorsVertexBufferObject);
	glBindVertexArray(0);
}

void Mesh::CreateMesh(GLint vertexCount) {
	_vertexCount = vertexCount;
	glGenVertexArrays(1, &_vertexArrayObject);
	glBindVertexArray(_vertexArrayObject);
}

void Mesh::Draw(GLenum primitive) {
	glBindVertexArray(_vertexArrayObject);
	if (_indicesCount > 0)
		glDrawElements(primitive, _indicesCount, GL_UNSIGNED_INT, nullptr);
	else
		glDrawArrays(primitive, 0, _vertexCount);

	glBindVertexArray(0);
}

void Mesh::SetPositionAttribute(std::vector<glm::vec2> positions, GLenum usage, GLuint locationIndex) {
	if (positions.size() == 0 || positions.size() != _vertexCount) {
		return;
	}

	SetAttributeData(_positionsVertexBufferObject, sizeof(glm::vec2) * positions.size(), positions.data(), usage, locationIndex, 2);
}
void Mesh::SetPositionAttribute(std::vector<glm::vec3> positions, GLenum usage, GLuint locationIndex) {
	if (positions.size() == 0 || positions.size() != _vertexCount) {
		return;
	}

	SetAttributeData(_positionsVertexBufferObject, sizeof(glm::vec3) * positions.size(), positions.data(), usage, locationIndex, 3);
}
void Mesh::SetColorAttribute(std::vector<glm::vec3> colors, GLenum usage, GLuint locationIndex) {
	if (colors.size() == 0 || colors.size() != _vertexCount) {
		return;
	}

	SetAttributeData(_colorsVertexBufferObject, sizeof(glm::vec3) * colors.size(), colors.data(), usage, locationIndex, 3);
}
void Mesh::SetColorAttribute(std::vector<glm::vec4> colors, GLenum usage, GLuint locationIndex) {
	if (colors.size() == 0 || colors.size() != _vertexCount) {
		return;
	}

	SetAttributeData(_colorsVertexBufferObject, sizeof(glm::vec3) * colors.size(), colors.data(), usage, locationIndex, 3);
}

void Mesh::SetNormalAttribute(std::vector<glm::vec3> normal, GLenum usage, GLuint locationIndex) {
	if (normal.size() != 0 && normal.size() == int(_vertexCount)) {
		for (size_t i = 0; i < normal.size(); i++)
			normal[i].z *= -1;

		SetAttributeData(_normalVertexBufferObject, sizeof(glm::vec3) * normal.size(),
			normal.data(), usage, locationIndex, 3);
	}
}

void Mesh::SetIndices(std::vector<unsigned int> indices, GLenum usage) {
	if (indices.size() > 0) {
		glBindVertexArray(_vertexArrayObject);
		glGenBuffers(1, &_indicesBufferObject);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indicesBufferObject);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), indices.data(), usage);
		_indicesCount = indices.size();
		glBindVertexArray(0);
	}
}



void Mesh::SetAttributeData(GLuint & buffer, const GLsizeiptr size, const void * data, GLenum usage, GLuint locationIndex, const GLint components) {
	glDeleteBuffers(1, &buffer); //
	glGenBuffers(1, &buffer); //
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, size, data, usage);
	glEnableVertexAttribArray(locationIndex);
	glVertexAttribPointer(locationIndex, components, GL_FLOAT, GL_FALSE, 0, nullptr); //
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void Mesh::SetTexCoordAttribute(std::vector<glm::vec2> texCoords,
	GLenum usage,
	GLuint locationIndex)
{
	if (texCoords.size() > 0 && texCoords.size() == _vertexCount)
	{
		SetAttributeData(_texCoordsVertexBufferObject,	sizeof(glm::vec2) * texCoords.size(),texCoords.data(),usage,locationIndex,2);
	}
}