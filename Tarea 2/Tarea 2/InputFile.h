/***********************************************************************
Materia:		Gráficas Computacionales
Fecha:			21 de Agosto del 2017
Autor:			A01167344 Alumno Jorge luis Alvarado Durán
************************************************************************/

#pragma once
#include <string>

class InputFile {

public:
	bool Read(std::string filename);
	std::string GetContents();

private:
	std::string _contents;

};
