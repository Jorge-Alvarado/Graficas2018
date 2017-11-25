#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include "Transform.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Camera.h"
#include <iostream>
#include <vector>
#include <IL/il.h>
#include "Textura2D.h"


/******************************************
Materia:Gráficas Computacionales Gráficas
Fecha: 02/10/2017
Autor: A01167344 Jorge Luis Alvaraod Durán
*******************************************/

Mesh _mesh;
ShaderProgram _shaderProgram;
Transform _transform, _transform3, _transform4;
Camera _camera;
float t;
Textura2D myTexture;
Textura2D myTexture2;

void Initialize()
{
	std::vector<glm::vec3> positions;
	positions.push_back(glm::vec3(-3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, -3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, -3.0f, -3.0f));//3

	std::vector<glm::vec3> normal;
	normal.push_back(glm::vec3(0.0f, -3.0f, 0.0f));
	normal.push_back(glm::vec3(0.0f, -3.0f, 0.0f));
	normal.push_back(glm::vec3(0.0f, -3.0f, 0.0f));
	normal.push_back(glm::vec3(0.0f, -3.0f, 0.0f));

	positions.push_back(glm::vec3(-3.0f, -3.0f, 3.0f));//4
	positions.push_back(glm::vec3(-3.0f, 3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, 3.0f));

	normal.push_back(glm::vec3(0.0f, 0.0f, 3.0f));
	normal.push_back(glm::vec3(0.0f, 0.0f, 3.0f));
	normal.push_back(glm::vec3(0.0f, 0.0f, 3.0f));
	normal.push_back(glm::vec3(0.0f, 0.0f, 3.0f));

	positions.push_back(glm::vec3(-3.0f, 3.0f, -3.0f));//8
	positions.push_back(glm::vec3(3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, 3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, 3.0f));

	normal.push_back(glm::vec3(0.0f, 3.0f, 0.0f));
	normal.push_back(glm::vec3(0.0f, 3.0f, 0.0f));
	normal.push_back(glm::vec3(0.0f, 3.0f, 0.0f));
	normal.push_back(glm::vec3(0.0f, 3.0f, 0.0f));

	positions.push_back(glm::vec3(-3.0f, -3.0f, -3.0f));//12
	positions.push_back(glm::vec3(3.0f, -3.0f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, -3.0f));

	normal.push_back(glm::vec3(0.0f, 0.0f, -3.0f));
	normal.push_back(glm::vec3(0.0f, 0.0f, -3.0f));
	normal.push_back(glm::vec3(0.0f, 0.0f, -3.0f));
	normal.push_back(glm::vec3(0.0f, 0.0f, -3.0f));

	positions.push_back(glm::vec3(-3.0f, 3.0f, 3.0f));//16
	positions.push_back(glm::vec3(-3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, -3.0f, -3.0f));

	normal.push_back(glm::vec3(-3.0f, 0.0f, 0.0f));
	normal.push_back(glm::vec3(-3.0f, 0.0f, 0.0f));
	normal.push_back(glm::vec3(-3.0f, 0.0f, 0.0f));
	normal.push_back(glm::vec3(-3.0f, 0.0f, 0.0f));

	positions.push_back(glm::vec3(3.0f, -3.0f, -3.0f));//20
	positions.push_back(glm::vec3(3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, 3.0f));

	normal.push_back(glm::vec3(3.0f, 0.0f, 0.0f));
	normal.push_back(glm::vec3(3.0f, 0.0f, 0.0f));
	normal.push_back(glm::vec3(3.0f, 0.0f, 0.0f));
	normal.push_back(glm::vec3(3.0f, 0.0f, 0.0f));

	std::vector<glm::vec3> colors;
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.5f));

	//Texturas Cubo
	
	std::vector<glm::vec2> textures;
	textures.push_back(glm::vec2(0.0f, 0.0f));  
	textures.push_back(glm::vec2(1.0f, 0.0f)); 
	textures.push_back(glm::vec2(1.0f, 1.0f)); 
	textures.push_back(glm::vec2(0.0f, 1.0f)); 
											 
	textures.push_back(glm::vec2(0.0f, 0.0f)); 
	textures.push_back(glm::vec2(1.0f, 0.0f)); 
	textures.push_back(glm::vec2(1.0f, 1.0f)); 
	textures.push_back(glm::vec2(0.0f, 1.0f)); 

	textures.push_back(glm::vec2(0.0f, 0.0f)); 
	textures.push_back(glm::vec2(1.0f, 0.0f)); 
	textures.push_back(glm::vec2(1.0f, 1.0f)); 
	textures.push_back(glm::vec2(0.0f, 1.0f)); 

	textures.push_back(glm::vec2(0.0f, 0.0f));  
	textures.push_back(glm::vec2(1.0f, 0.0f)); 
	textures.push_back(glm::vec2(1.0f, 1.0f)); 
	textures.push_back(glm::vec2(0.0f, 1.0f)); 
											   
	textures.push_back(glm::vec2(1.0f, 1.0f)); 
	textures.push_back(glm::vec2(0.0f, 1.0f)); 
	textures.push_back(glm::vec2(0.0f, 0.0f)); 
	textures.push_back(glm::vec2(1.0f, 0.0f));  

	textures.push_back(glm::vec2(1.0f, 0.0f)); 
	textures.push_back(glm::vec2(0.0f, 1.0f)); 
	textures.push_back(glm::vec2(0.0f, 0.0f)); 
	textures.push_back(glm::vec2(1.0f, 1.0f)); 

	//Para afuera 
	std::vector<unsigned int> indices = { 0,2,3,3,1,0, 5,4,6,6,7,5, 8,10,11,11,9,8, 15,13,12,12,14,15, 18,19,17,17,16,18, 23,21,20,20, 22, 23 };

	//Crea el mesh
	_mesh.CreateMesh(24);
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	_mesh.SetNormalAttribute(normal, GL_STATIC_DRAW, 2);
	_mesh.SetIndices(indices, GL_STATIC_DRAW);
	_mesh.SetTexCoordAttribute(textures, GL_STATIC_DRAW, 3);


	_shaderProgram.CreateProgram();
	_shaderProgram.Activate();
	_shaderProgram.AttachShader("Transform.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("Defaultl.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_shaderProgram.SetAttribute(2, "VertexNormal");
	_shaderProgram.SetAttribute(3, "VertexTexCoord");

	_shaderProgram.LinkProgram();
	_shaderProgram.Deactivate();

	_shaderProgram.Activate();
	_shaderProgram.SetUniformf("iResolution", 400.0f, 400.0f);
	_shaderProgram.SetUniformf("lightPosition", 1.5f, 4.0f, 8.0f);
	_shaderProgram.SetUniformf("lightColor", 1.0f, 1.0f, 1.0f);



	_shaderProgram.Deactivate();

	t = 0.0f;
	_camera.MoveForward(30.0f, true);

	myTexture.LoadTexture("caja.jpg");
	myTexture2.LoadTexture("cajaGrande.jpg");

	
}

void Idle()
{
	glutPostRedisplay();
}

void GameLoop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_shaderProgram.Activate();
	myTexture.LoadTexture("cajaGrande.jpg");
	glm::vec3 camPos = _camera.GetPosition();

	t += 0.01f;
	_shaderProgram.SetUniformf("iGlobalTime", t);
	_transform3.SetPosition(0.0f, -8.0f, 0.0f);
	_transform3.SetScale(25.0f, 1.0f, 25.0f);
	
	_shaderProgram.SetUniformf("CameraPosition", camPos.x, camPos.y, -camPos.z);
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform3.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("modelMatrix", _transform3.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform3.GetModelMatrix());
	_shaderProgram.SetUniformf("CameraPosition", camPos.x, camPos.y, -camPos.z);
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform3.GetModelMatrix());
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	_shaderProgram.Deactivate();

	//-----------------------------------------

	_shaderProgram.Activate();

	myTexture2.LoadTexture("caja.jpg");
	_transform4.SetRotation(0.0f, t, t);
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform4.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform4.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("nMatrix", glm::mat3(glm::transpose(glm::inverse(_transform4.GetModelMatrix()))));
	_shaderProgram.SetUniformi("DiffuseTexture", 0);

	//TEXTURAS
	glActiveTexture(GL_TEXTURE1);
	myTexture.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE1);
	myTexture.Unbind();
	_shaderProgram.Deactivate();

	//-------------------------------------------

	// Cambiar el buffer actual.
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


	// Inicializar DevIL
	ilInit();
	// Le decimos que queremos cambiar el punto de origen
	ilEnable(IL_ORIGIN_SET);
	// Configuramos el origen de las texturas cargadas por
	// DevIL como abajo a la izquierda
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);


	Initialize();

	glutMainLoop();

	return 0;
}