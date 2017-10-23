#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include "Transform.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Camera.h"
#include <iostream>
#include <vector>

/*********************************************
Materia:Gráficas Computacionales Gráficas
Fecha: 02/10/2017
Autor: A01167344 Jorge Luis Alvardo Durán
*********************************************/

Mesh _mesh;
Mesh _mesh1;
ShaderProgram _shaderProgram;
Transform _transform, _transform2, _transform3, _transform4, _transform5;
Camera _camera;
float t, s, v, x;
int i, radio = 5, triangulos = 360, center = (0, 0);
float PI = 3.1416;
GLfloat PIx2 = 2.0f * PI;
bool bandera = true;
float contador = 0.0f;

//ui

void Initialize()
{

	std::vector<glm::vec3> positions;
	positions.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	positions.push_back(glm::vec3(-1.0f, -1.0f, -1.0f));
	positions.push_back(glm::vec3(-1.0f, -1.0f, 1.0f));
	positions.push_back(glm::vec3(1.0f, -1.0f, 1.0f));
	positions.push_back(glm::vec3(1.0f, -1.0f, -1.0f));

	std::vector<glm::vec3> colors;
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.5f));
												  
												  
	std::vector<unsigned int> indices = { 0,2,3, 0,3,4, 0,4,1, 0,1,2, 2,1,4, 4,3,2 };
	
	_mesh.CreateMesh(5);
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);



	_shaderProgram.CreateProgram();
	_shaderProgram.Activate();
	_shaderProgram.AttachShader("Default.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("Default.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	//lamamos el indice
	_mesh.SetIndices(indices, GL_STATIC_DRAW);
	//_mesh1.SetIndices(indics, GL_STATIC_DRAW);

	_shaderProgram.LinkProgram();
	_shaderProgram.Deactivate();

	_shaderProgram.Activate();
	//
	_shaderProgram.SetUniformf("iResolution", 400.0f, 400.0f);
	_shaderProgram.Deactivate();

	t = 0.0f;
	s = 0.0f;
	bandera = true;
	//_camera.SetOrthographic(15.0f, 1.0f);
	_camera.MoveForward(25.0f, true);
}

void Idle() {
	glutPostRedisplay();
}

void GameLoop()
{


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_shaderProgram.Activate();

	t += 0.01f;
	_shaderProgram.SetUniformf("iGlobalTime", t);
	_transform.SetRotation(t * 2, t * 8, t * 4);
	_transform.SetPosition(0 + (radio*cos(v*PIx2 / triangulos)), 0 + (radio*sin(v*PIx2 / triangulos)), 0.0f);
	v = v + 0.07f;
	//Gira en 3D
	_transform.SetScale(3.0f, 3.0f, 3.0f);
	_transform2.SetPosition(0.0f, 0.0f, 0.0f);
	_transform2.SetRotation(t * -2, t * -8, t * -4);


	if (contador >= 0.0f && bandera == true) {
		x = x + 0.0005f;
		_transform2.SetScale(.5f + x, .5f + x, .5f + x);
		contador = contador + 0.0005f;
	}

	if (contador >= 0.5f) {
		bandera = false;
	}

	if (bandera == false) {
		x = x - 0.0005f;
		_transform2.SetScale(.5f + x, .5f + x, 0.5f + x);
		contador = contador - 0.0005f;
	}

	if (contador < 0.0f && bandera == false) {
		bandera = true;
		contador = 0.0f;
	}

	
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix());

	_mesh.Draw(GL_TRIANGLES);
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform2.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLES);
	
	_shaderProgram.Deactivate();

	glutSwapBuffers();
}

int main(int argc, char* argv[])
{

	glutInit(&argc, argv);
	//version
	glutInitContextVersion(4, 0);

	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);

	glutCreateWindow("Hello World GL");

	glutDisplayFunc(GameLoop);
	glutIdleFunc(Idle);

	glewInit();
	//Color de la pantalla
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	Initialize();

	glutMainLoop();

	return 0;
}