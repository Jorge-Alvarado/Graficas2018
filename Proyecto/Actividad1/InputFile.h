/***************************
Materia:Gr�ficas Computacionales Gr�ficas
Fecha: 02/10/2017
Autor: A01167344 Jorge Luis Alvarado Dur�n
*****************************/
#pragma once
#include <string>

class InputFile {
private:
	std::string _contents;

public:
	bool Read(std::string _fileName);
	std::string GetContents();
};