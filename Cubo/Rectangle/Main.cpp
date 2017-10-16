#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Transform.h"
#include "Camera.h"

Mesh _mesh;
ShaderProgram _shaderProgram;
Transform _transform;
Camera _camera;
float _tiempo;


void Initialize()
{
	std::vector<glm::vec3> positions;
	//cara inf roja 0 1 2 3
	positions.push_back(glm::vec3(-3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, -3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, -3.0f, -3.0f));

	//cara frontal verde 4 5 6 7
	positions.push_back(glm::vec3(-3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, 3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, 3.0f));

	//cara sup naranja 8 9 10 11
	positions.push_back(glm::vec3(-3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, 3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, 3.0f));

	//cara trasera azul 12 13 14 15
	positions.push_back(glm::vec3(-3.0f, -3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, -3.0f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, -3.0f));

	//cara izq amarillo 16 17 18 19
	positions.push_back(glm::vec3(-3.0f, 3.0f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, -3.0f, -3.0f));

	//cara der rosa 20 21 22 23
	positions.push_back(glm::vec3 (3.0f, -3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, 3.0f));


	//*COLORES

	std::vector<glm::vec3> colors;


	colors.push_back(glm::vec3(0.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 0.0f));

	
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));



	colors.push_back(glm::vec3(1.0f, 0.0f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.5f));


	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));


	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));


	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));



	//								inf				frontal		sup				trasera				izq				der
	std::vector<unsigned int> indices = { 0,1,2,1,3,2, 4,5,6,5,7,6, 8,9,10,9,11,10, 12,13,14,13,15,14, 16,17,18,17,19,18, 20,21,22,21,23,22 };


	_mesh.CreateMesh(24);
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);

	_shaderProgram.CreateProgram();
	_shaderProgram.Activate();
	_shaderProgram.AttachShader("Default.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("Default.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0,"VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_mesh.SetIndices(indices, GL_STATIC_DRAW);
	_shaderProgram.LinkProgram();
	_shaderProgram.Deactivate();

	_shaderProgram.Activate();
	_shaderProgram.SetUniformf("iResolution", 400.0f, 400.0f);
	_shaderProgram.Deactivate();

	_tiempo = 0.0f;

	//_transform.SetRotation(45.0f, 0.0f,  45.0f);

	_camera.SetOrthographic(7.0f, 1.0f);
}




void GameLoop()
{

	// Limpiamos el buffer de color y el buffer de profunidad.
	// Siempre hacerlo al inicio del frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_shaderProgram.Activate();

	_shaderProgram.SetUniformf("_tiempo", _tiempo);
	//_camera.MoveForward(0.0001f);
	_transform.SetRotation(_tiempo * 2, _tiempo * 4, _tiempo * 8);
	//_transform.Rotate(0.0f, 0.1f, 0.0f, true); //false ejes locales, Lo va a girar en torno de su arriba



	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix",_camera.GetViewProjection() * _transform.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLES);
	_shaderProgram.Deactivate();

	_tiempo += 0.001f;


	// Cuando terminamos de renderear, cambiamos los buffers.
	glutSwapBuffers();

}



void Idle()

{

	// Cuando OpenGL entra en modo de reposo 
	// (para guardar bateria, por ejemplo)
	// le decimos que vuelva a dibujar ->
	// Vuelve a mandar a llamar GameLoop
	glutPostRedisplay();

}



void ReshapeWindow(int width, int height)
{
	glViewport(0, 0, width, height);

}



int main(int argc, char* argv[])
{

	// Inicializar freeglut
	// Freeglut se encarga de crear una ventana
	// en donde podemos dibujar
	glutInit(&argc, argv);

	// Solicitando una versión específica de OpenGL.
	glutInitContextVersion(4, 4);

	// Iniciar el contexto de OpenGL. El contexto se refiere
	// a las capacidades que va a tener nuestra aplicación
	// gráfica.
	// En este caso estamos trabajando con el pipeline programable.
	glutInitContextProfile(GLUT_CORE_PROFILE);

	// Freeglut nos permite configurar eventos que ocurren en la ventana.
	// Un evento que nos interesa es cuando alguien cierra la ventana.
	// En este caso, simplemente dejamos de renderear la esscena y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	// Configuramos el framebuffer. En este caso estamos solicitando un buffer
	// true color RGBA, un buffer de profundidad y un segundo buffer para renderear.
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

	// Iniciar las dimensiones de la ventana (en pixeles)
	glutInitWindowSize(400, 400);

	// Creamos la ventana y le damos un título.
	glutCreateWindow("Hello World GL");

	// Asociamos una función de render.
	//Esta función se mandará a llamar para dibujar un frame.
	glutDisplayFunc(GameLoop);

	// Asociamos una función para el cambio de resolución

	// de la ventana. Freeglut la va a mandar a llamar

	// cuando alguien cambie el tamaño de la venta.

	glutReshapeFunc(ReshapeWindow);

	// Asociamos la función que se mandará a llamar

	// cuando OpenGL entre en modo de reposo.

	glutIdleFunc(Idle);



	// Inicializar GLEW. Esta librería se encarga de obtener el API de OpenGL de

	// nuestra tarjeta de video. SHAME ON YOU MICROSOFT.

	glewInit();



	// Configurar OpenGL. Este es el color por default del buffer de color

	// en el framebuffer.

	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);

	// Ademas de solicitar el buffer de profundidad, tenemos

	// que decirle a OpenGL que lo queremos activo

	glEnable(GL_DEPTH_TEST);

	// Activamos el borrado de caras traseras.

	// Ahora todos los triangulos que dibujemos deben estar en CCW

	glEnable(GL_CULL_FACE);

	// No dibujar las caras traseras de las geometrías.

	glCullFace(GL_BACK);



	std::cout << glGetString(GL_VERSION) << std::endl;



	// Configuración inicial de nuestro programa.

	Initialize();



	// Iniciar la aplicación. El main se pausará en esta línea hasta que se cierre

	// la venta de OpenGL.

	glutMainLoop();



	return 0;

}