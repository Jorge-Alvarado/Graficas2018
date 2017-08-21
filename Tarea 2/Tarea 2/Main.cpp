/***********************************************************************
Materia:		Gráficas Computacionales
Fecha:			21 de Agosto del 2017
Autor:			A01167344 Alumno Jorge luis Alvarado Durán
************************************************************************/

#include <iostream>
#include "InputFile.h"

int main(int argc, char* argv[]) {

	InputFile inputfile;

	std::string filename = "Prueba.txt";
	InputFile myFile;
	myFile.Read(filename);
	std::string contents = myFile.GetContents();

	std::cout << "Contents: " << contents << std::endl;

	std::cin.get();

	return 0;
}

//Referencia: https://stackoverflow.com/questions/2912520/read-file-contents-into-a-string-in-c