/***********************************************************************
Materia:		Gráficas Computacionales
Fecha:			21 de Agosto del 2017
Autor:			A01167344 Alumno Jorge luis Alvarado Durán
************************************************************************/

#include "InputFile.h"
#include<fstream>

bool InputFile::Read(std::string filename)
{
	
	std::ifstream abrir(filename);
	std::string archivo_compiado((std::istreambuf_iterator<char>(abrir)), std::istreambuf_iterator<char>());
	_contents = archivo_compiado;
	std::ifstream myReadFile;
	myReadFile.open(filename);
	

	if (myReadFile.is_open()) {
		//while (!myReadFile.eof()) {
		myReadFile.close();
		return true;
			//myReadFile >> _contents;

		//}
	}
	else {
		_contents = "";
		return false;
	}

}

std::string InputFile::GetContents()
{
	
	return std::string(_contents);
	
}
