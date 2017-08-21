#include "Employee.h"

Employee::Employee() {
	_id = 0;
	_firstName = "Jorge";
	_lastName = "Alvarado";
	_salary = 1000;
}

Employee::Employee(int id, std::string firstName, std::string lastName, int salary)
{
	_id = id;
	_firstName = firstName;
	_lastName = lastName;
	_salary = salary;
}

std::string Employee::GetFirstName()
{
	return std::string(_firstName);
}

std::string Employee::GetLastName()
{
	return std::string(_lastName);
}

std::string Employee::GetName()
{
	std::string Nombre = _firstName + " " + _lastName;
	return std::string(Nombre);

}

int Employee::GetSalary()
{
	return _salary;
}

void Employee::SetSalary(int salary)
{
	_salary = salary;
}

int Employee::GetAnnualSalary()
{
	return _salary * 12;
}

int Employee::RaiseSalary(int percent)
{
	int resultado = _salary + (_salary / 10 * (percent/10));
	return resultado;
}

std::string Employee::Print()
{
	std::string print = _firstName + " " + _lastName;
	return std::string();
}