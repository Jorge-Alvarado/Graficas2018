#pragma once
#include <string>


class Rectangle {

public:
	Rectangle();
	Rectangle(float w, float h);

	float GetWith();
	void SetWidth(float w);
	float GetHeight();
	void SetHeight(float h);
	float GetArea();
	float GetPerimeter();

private:
	float _width;
	float _height;

};
