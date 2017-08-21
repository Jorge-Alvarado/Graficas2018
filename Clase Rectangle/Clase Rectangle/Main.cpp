#include <iostream>
#include "Rectangle.h"

int main() {

	Rectangle rectangulo(2.0, 2.0);
	std::cout << "El area del rectangulo es de: " <<rectangulo.GetArea() << std::endl;
	std::cout << "El perimetro del rectangulo es de: " << rectangulo.GetPerimeter() << std::endl;
	std::cout << "El ancho del rectangulo es: " <<rectangulo.GetWith() << std::endl;

	std::cin.get();

	return 0;
}