/******************************************************
Materia:			Gráficas Computacionales
Fecha:				14 de Agosto de 2016
Autor:				Jorge Luis Alvarado Durán
*******************************************************/

#include <iostream>

//PROBLEMA NUMERO 1
int PerimetroRectangulo(int base, int altura) {
	int resultado = 0;
	resultado = (2 * base) + (2 * altura);
	return resultado;
}

//PROBLEMA NUMERO 2
float AreaTriangulo(float base, float altura) {
	float resultado = 0;
	resultado = (base * altura) / 2;
	return resultado;
}

//PROBLEMA NUMERO 3
int Mayor(int numero1, int numero2, int numero3) {
	int resultado = numero1;
	if (numero2 > numero1 && numero2 > numero3) {
		resultado = numero2;
		return resultado;
	}
	if (numero3 > numero1 && numero3 > numero1) {
		resultado = numero3;
		return resultado;
	}
	return resultado;
}

//PROBLEMA NUMERO 4
int Menor(int numero1, int numero2, int numero3) {
	int resultado = numero1;
	if (numero2 < numero1 && numero2 < numero3) {
		resultado = numero2;
		return resultado;
	}
	if (numero3 < numero1 && numero3 < numero1) {
		resultado = numero3;
		return resultado;
	}
	return resultado;
}

//PROBLEMA NUMERO 5
void FilaEstrellas(int n) {
	for (int i = 0; i < n; i++) {
		std::cout << "*";
	}
	std::cout << std::endl;
}

//PROBLEMA NUMERO 6
void MatrizEstrellas(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}

//PROBLEMA NUMERO 7
void PiramideEstrellas(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}

//PROBLEMA NUMERO 8
void FlechaEstrellas(int n) {
	int numero = 1;
	int maximo = (n * 2) - 1;

	for (int i = 1; i < maximo + 1; i++) {
		for (int j = 0; j < numero; j++) {
			std::cout << "*";
		}
		if (i < n) {
			numero++;
		}
		if (i >= n) {
			numero = numero - 1;
		}
		std::cout << std::endl;
	}
}

//PROBLEMA NUMERO 9
void Fibonacci(int n) {
	int numero = 1;
	int anterior = 0;
	int resultado = 0;
	std::cout << numero << " ";

	for (int i = 0; i < n - 1; i++) {
		resultado = numero + anterior;
		std::cout << resultado << " ";
		anterior = numero;
		numero = resultado;
	}
	std::cout << std::endl;
}

//PROBLEMA NUMERO 10
bool EsPrimo(int numero) {
	bool resultado = true;
	int inicio = 1;
	int final = numero;

	for (int i = inicio + 1; i < final - 1; i++) {
		if (numero % i == 0) {
			return false;
		}
	}

	if (numero % inicio == 0 && numero % numero == 0) {
		return true;
	}

}

int main() {

	//PROBLEMA NUMERO 1
	int p = PerimetroRectangulo(5, 3);
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << "1. El perimetro del rectagulo es: " << std::endl;
	std::cout << p << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	//PROBLEMA NUMERO 2
	float a = AreaTriangulo(5.0f, 3.0f);
	std::cout << "2. El area del triangulo es: " << std::endl;
	std::cout << a << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	//PROBLEMA NUMERO 3
	int mayor = Mayor(5, 9, 1);
	std::cout << "3. El numero mayor es: " << std::endl;
	std::cout << mayor << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	//PROBLEMA NUMERO 4
	int menor = Menor(5, 9, 1);
	std::cout << "4. El numero menor es: " << std::endl;
	std::cout << menor << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	//PROBLEMA NUMERO 5
	std::cout << "5. " << std::endl;
	FilaEstrellas(5);
	std::cout << "------------------------------------------------" << std::endl;
	//PROBLEMA NUMERO 6
	std::cout << "6. " << std::endl;
	MatrizEstrellas(4);
	std::cout << "------------------------------------------------" << std::endl;
	//PROBLEMA NUMERO 7
	std::cout << "7. " << std::endl;
	PiramideEstrellas(6);
	std::cout << "------------------------------------------------" << std::endl;
	//PROBLEMA NUMERO 8
	std::cout << "8. " << std::endl;
	FlechaEstrellas(3);
	std::cout << "------------------------------------------------" << std::endl;
	//PROBLEMA NUMERO 9
	std::cout << "9. " << std::endl;
	Fibonacci(9);
	std::cout << "------------------------------------------------" << std::endl;
	//PROBLEMA NUMERO 10
	std::cout << "10. " << std::endl;
	bool primo = EsPrimo(79);
	std::cout << primo << std::endl;
	bool primo2 = EsPrimo(52);
	std::cout << primo2 << std::endl;

	std::cin.get();
}