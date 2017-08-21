#include "Rectangle.h"

Rectangle::Rectangle() {
	_width = 1.0;
	_height = 1.0;
}

Rectangle::Rectangle(float w, float h)
{
	_width = w;
	_height = h;
}

float Rectangle::GetWith()
{
	return _width;
}

void Rectangle::SetWidth(float w)
{
	_width = w;
}

float Rectangle::GetHeight()
{
	return _height;
}

void Rectangle::SetHeight(float h)
{

}

float Rectangle::GetArea()
{
	return (_width * _height);
}

float Rectangle::GetPerimeter()
{
	return (_width * 2) + (_height * 2);
}