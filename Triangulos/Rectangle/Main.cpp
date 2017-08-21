#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

void GameLoop(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);

	glColor3f(1.0f,0.0f,0.0f);
	glVertex2f(-1.0f,-1.0f);
	glColor3f(0.0f,1.0f,0.0f);
	glVertex2f(1.0f,-1.0f);
	glColor3f(0.0f, 0.0f,1.0f);
	glVertex2f(0.0f,1.0f);

	glEnd();

	glutSwapBuffers();

}

int main(int argc, char*argv[]) {

	//Inicializar freeglut
	//Freeglut se encarga de crear una ventana
	//en donde podemos dibujar
	glutInit(&argc, argv);
	//Inicar el conttexto de OpenGL. El contexto se refiere a las capacidades que va a tener nuestra aplicacion grafica
	//En este caso estamos trabajando con el pipeline clasico.

	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);


	//Freeglut nos permite configurar eventos que ocurren en la ventana.
	//Un evento que nos interesa es cuando alguien cierra la ventana
	//En este caso, simplemente dejamos de renderear la escena y terminamos el programa
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	//Configuramos el framebuffer. En este caso estamos solicitando un buffer true color RGBA, un buffer de profundidad y un segundo buffer para renderear
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

	glutInitWindowSize(400, 400);
	//Creamos la ventana y le damos un titulo
	glutCreateWindow("Hello World GL");

	//Esta funcion se llamara para llamar para dibujar un frame
	glutDisplayFunc(GameLoop);

	//Inicializamos GLEW. Esta libreria se encarga de obtener el API de OpenGL de nuestra tarjeta de video.
	glewInit();

	//Configurar OpenGL. Color por default del buffer de color en el framebuffer
	glClearColor(1.0f, 1.0f, 1.0f,1.0f);

	//Iniciar la aplicacion. El main se pausara en esta linea hasta que se cierre la ventana de OpenGL
	glutMainLoop();
	
	return 0;
	
}