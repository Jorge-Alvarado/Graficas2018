#include <iostream>
#include "Circle.h"

int main() {

	Circle circulo(2.0,"green");
	std::cout <<"El radio es de: " <<circulo.GetRadius() << std::endl;
	std::cout <<"El area es de: "<< circulo.GetArea() << std::endl;
	std::cout << "El color es: " << circulo.GetColor() << std::endl;

	std::cin.get();

	return 0;
}