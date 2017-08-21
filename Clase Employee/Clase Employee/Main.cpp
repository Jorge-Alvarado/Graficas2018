#include <iostream>
#include "Employee.h"

int main() {

	Employee employee(0,"Jorge","Alvarado",1000);
	std::cout << employee.GetName() << " gana al mes "<< employee.GetSalary() << std::endl;
	std::cout << "El salario anual de " << employee.GetFirstName() << " " << employee.GetLastName() << " es de: "<< employee.GetAnnualSalary() << std::endl;
	std::cout << "Si tiene un aumento del 50% sobre su salario, ganaria ahora: " <<employee.RaiseSalary(50) << std::endl;

	std::cin.get();
	return 0;
}