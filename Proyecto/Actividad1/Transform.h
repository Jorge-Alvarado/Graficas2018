/***************************
Materia:Gr�ficas Computacionales Gr�ficas
Fecha: 02/10/2017
Autor: A01167344 Jorge Luis Alvarado Dur�n
*****************************/
#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

class Transform {
public:
	Transform();

	glm::mat4 GetModelMatrix();
	glm::vec3 GetPosition();
	glm::quat GetRotation();
	glm::vec3 GetScale();

	void SetPosition(float x, float y, float z);//Este te manda a la posicion que le des
	void SetRotation(float x, float y, float z);
	void SetScale(float x, float y, float z);

	void Translate(float x, float y, float z, bool world); //Este es movimiento, suma a donde llegar
	void MoveForward(float delta, bool world);
	void MoveUp(float delta, bool world);
	void MoveRight(float delta, bool world);
	void Rotate(float x, float y, float z, bool world);

	static constexpr glm::vec3 WORLD_FORWARD_VECTOR = glm::vec3(0.0f, 0.0f, 1.0f);
	static constexpr glm::vec3 WORLD_UP_VECTOR = glm::vec3(0.0f, 1.0f, 0.0f);
	static constexpr glm::vec3 WORLD_RIGHT_VECTOR = glm::vec3(1.0f, 0.0f, 0.0f);

private:
	void UpdateLocalVectors();
	void UpdateModelMatrixPosition();
	void UpdateModelMatrixRotationScale();

	glm::mat4 _modelMatrix;

	glm::vec3 _position;
	glm::quat _rotation;
	glm::vec3 _scale;

	glm::vec3 _forward; //Hac�a a donde esta apuntando, el vector hacia adelante del objeto.
	glm::vec3 _up;
	glm::vec3 _right;
};