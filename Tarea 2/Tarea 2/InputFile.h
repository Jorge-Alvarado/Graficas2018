/***********************************************************************
Materia:		Gr�ficas Computacionales
Fecha:			21 de Agosto del 2017
Autor:			A01167344 Alumno Jorge luis Alvarado Dur�n
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
