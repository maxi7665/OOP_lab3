#include <iostream>
#include "Polygon.h"

Polygon::Polygon(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	this->x1 = x1;
	this->x2 = x2;
	this->x3 = x3;
	this->x4 = x4;

	this->y1 = y1;
	this->y2 = y2;
	this->y3 = y3;
	this->y4 = y4;
}

Polygon::~Polygon()
{
	std::cout << "Desctruction of polygon "
		<< "[" << x1 << y1 << "],"
		<< "[" << x2 << y2 << "],"
		<< "[" << x3 << y3 << "],"
		<< "[" << x4 << y4 << "]"
		<< std::endl;
}