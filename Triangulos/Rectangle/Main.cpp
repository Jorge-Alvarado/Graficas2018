#include <iostream>
#include <GL/glew.h> /Obtiene la ultima version de GL, va en <> pues se importa de fuera/
#include <GL/freeglut.h>
#include <vector>
#include <glm/glm.hpp> //Datos con dos o mas componentes 
#include "InputFile.h"


//Identificador del manager al que vamos a asociar todos los VBO´s
GLuint vao;

//Identificador del manager de los shader (shaderProgram)
GLuint shaderProgram;

void Initialize() {
	//Creando toda la memoria que el prograba va a utilizar

	//Creacion del atributo de posiciones de los vertices
	//Esta es una lista de vec2
	//Esto es en el CPU
	std::vector<glm::vec2> positions;
	positions.push_back(glm::vec2(-0.6f, -0.8f));
	positions.push_back(glm::vec2(-0.3f, -0.4f));
	positions.push_back(glm::vec2(0.6f, -0.8f));
	positions.push_back(glm::vec2(0.3f, -0.4f));
	positions.push_back(glm::vec2(0.9f, 0.3f));
	positions.push_back(glm::vec2(0.44f, 0.18f));
	positions.push_back(glm::vec2(0.0f, 1.0f));
	positions.push_back(glm::vec2(0.0f, 0.5f));
	positions.push_back(glm::vec2(-0.9f, 0.3f));
	positions.push_back(glm::vec2(-0.44f, 0.18f));
	positions.push_back(glm::vec2(-0.6f, -0.8f));
	positions.push_back(glm::vec2(-0.3f, -0.4f));




	//se crea la lista y se le da Nombre de la lista 
	std::vector<glm::vec3> color;

	for (int i = 0; i < 13; i++) {
		color.push_back(glm::vec3(0.0f, 0.0f, 0.0f));
	}
	


	//Queremos geenerar un manager 
	glGenVertexArrays(1, &vao);
	//Utilizar el vao. A parti de este momento, todos los vBO´s creados y configurados
	glBindVertexArray(vao);

	//Identificador del VBO de posiciones 
	GLuint positionsVBO;
	//Creacion del VBO de posiciones
	glGenBuffers(1, &positionsVBO);//Cuantos y donde queremos almacenarlo
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
	//Creamos la memoria y la incializamos con los daos del atributo de posiciones
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2)*positions.size(), positions.data(), GL_STATIC_DRAW);
	//Activamos este numero de atributo en la tarjeta de video.
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	//Ya no vamos a utilizar VBO en este momento.
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLuint colorsVBO;
	glGenBuffers(1, &colorsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, colorsVBO);//Inicializamos el buffer con el atributo color
											 //Madamos los datos a la tarjeta de video
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*color.size(), color.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0); //Le decimos que ya no quiero utilizarlo


									  //Desactivamos el manager
	glBindVertexArray(0);

	//Creamos un objeto para leer archivos de texto
	InputFile ifile;

	//VERTEX SHADER
	//Leemos el archivo default.vert donde esta el codigo del vertex shader
	ifile.Read("Default.vert");
	//obtenemos el codigo fuente y lo guardamos en un string 
	std::string vertexSource = ifile.GetContents();
	//Creamos un sahder de tipo vertex y guardamos su identificador en una variable.
	GLuint vertexshaderHandle = glCreateShader(GL_VERTEX_SHADER);
	//obtenmos los datos en el formato correcto.
	const GLchar *vertexSource_c = (const GLchar*)vertexSource.c_str();
	//Le estamos dando el codigo fuente a openGl para que se lo asigne a shader.
	glShaderSource(vertexshaderHandle, 1, &vertexSource_c, nullptr);
	//Compilamos el shader en busca de errores.
	//vamos a asumir que no hay ningun error.
	glCompileShader(vertexshaderHandle);

	ifile.Read("Default.frag");
	std::string fragmentSource = ifile.GetContents();
	GLuint fragmentShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
	const GLchar *fragmentSource_c = (const GLchar*)fragmentSource.c_str();
	glShaderSource(fragmentShaderHandle, 1, &fragmentSource_c, nullptr);
	glCompileShader(fragmentShaderHandle);

	//Creamos el identificador para el manager de los shader.
	shaderProgram = glCreateProgram();
	//Adjuntamos el vertex shader al manager(van a trabajar juntos).
	glAttachShader(shaderProgram, vertexshaderHandle);
	//Adjuntamos el fragment shader al manager(van a trabajar juntos).
	glAttachShader(shaderProgram, fragmentShaderHandle);
	//Asociamos un buffer con indice 0 (posiciones) a la variabble VertexPosition
	glBindAttribLocation(shaderProgram, 0, "VertexPosition");
	//Asociamos un buffer con indice 1(colores) a la variable VertexColor
	glBindAttribLocation(shaderProgram, 1, "VertexColor");
	//Ejecutamos el proceso de linker (aseguramos que el vertex y fragment son compatibles)
	glLinkProgram(shaderProgram);

}


void GameLoop() {
	//Limpiamos el buffer de color y el de profundidad. siempre hacerlo al inico del frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Activamos el vertex Shader y el fragment shader utilizando el manager
	glUseProgram(shaderProgram);

	//Activamos el manager y en este momento se activan todos los VBO´s asociados automaticamente
	glBindVertexArray(vao);
	//Funcion de dibujo sin indices 
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 12);//Aqui dice que solo se dibujan 3 vertices
										   //Terminamos de usar el manager
	glBindVertexArray(0);

	//Desactivamos el manager
	glUseProgram(0);

	//Warning.!!! Esto es openGL viejo. Solamente se utilizara esta clase.
	//glBegin(GL_TRIANGLES);
	///Rojo verde azul
	/*glColor3f(1.0f, 0.0f, 0.0f);
	//Vertices 2f=X y Y
	glVertex2f(-1.0f, -1.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, -1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.0f, 1.0f);*/

	//glEnd();

	//cuandot erminamos de renderear, cambiamos los buffers
	glutSwapBuffers();
}

int main(int argc, char* argv[]) {
	/*std::cout << "Hello world" << std::endl;
	Circle circulo(2.0, "green");
	std::cout << circulo.GetRadius() << std::endl;
	Rectangle rectangulo(2.0, 2.0);
	std::cout << rectangulo.GetWidth() << std::endl;
	std::cin.get();*/

	//Inicializar freeglut
	//Freeglut se encarga de crear una ventana
	//En donde podemos dibujar
	glutInit(&argc, argv);
	//Iniciar la versión especifica de openGL
	//glutInitContextVersion(4,4);
	//Iniciar el contexto de openGL. El contesto se refiere a las capacidades que tendra nuestra aplicacion grafica 
	//En este caso estamos trabajando con el pipeline clasico
	glutInitContextProfile(GLUT_CORE_PROFILE); //Abres la ventana para que sea compatible con el viejito gl
											   //Freeglut nos permite configurar eventos que ocurren en la ventana.
											   //Un evento que nos interesa es cuando alguien cierra la ventana. En este casi dejamos de renderear la escena y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	//Configuramos el framebuffer. En este caso estamos solicitando un buffer true color RGBA, un buffer de profundidad 
	//Y un segundo buffer para renderear.
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	//indicamos la dimension de nuestra pantalla en pixeles 
	glutInitWindowSize(600, 600);
	//Creamos la ventana y le damos un titulo
	glutCreateWindow("Hello World GL");

	//Asociamos una funcion de render, la cual se manadara a llamar para dibujar un frame 
	glutDisplayFunc(GameLoop);

	//Inicializamos GLEW. esta libreria se encarga de obtener el API de openGL de nuestra tarjeta de video. 
	glewInit();

	//Configurar OpenGL.}
	//Este es el color por default en el framebuffer (amarillo).
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	std::cout << glGetString(GL_VERSION) << std::endl;

	//configuracion incial de nujestro programa.
	Initialize();

	//iniciada la aplicación el main se va a pausar en esta linea hasta que se cierre la ventana OpenGL.
	glutMainLoop();

	return 0;
}