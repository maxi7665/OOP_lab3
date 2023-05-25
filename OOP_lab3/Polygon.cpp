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

bool Polygon::hasEqualSide(const Polygon& right_polygon)
{
	int leftPolygonTops[8] = {
		this->getX1(),
		this->getY1(),
		this->getX2(),
		this->getY2(),
		this->getX3(),
		this->getY3(),
		this->getX4(),
		this->getY4() };

	int rightPolygonTops[8] = {
		right_polygon.getX1(),
		right_polygon.getY1(),
		right_polygon.getX2(),
		right_polygon.getY2(),
		right_polygon.getX3(),
		right_polygon.getY3(),
		right_polygon.getX4(),
		right_polygon.getY4() };
}

int Polygon::getX1() { return this->x1; }
void Polygon::setX1(int x1) { this->x1 = x1; }
int Polygon::getY1() { return this->y1; }
void Polygon::setY1(int y1) { this->y1 = y1; }

int Polygon::getX2() { return this->x2; }
void Polygon::setX2(int x2) { this->x2 = x2; }
int Polygon::getY2() { return this->y2; }
void Polygon::setY2(int y2) { this->y2 = y2; }

int Polygon::getX3() { return this->x3; }
void Polygon::setX3(int x3) { this->x3 = x3; }
int Polygon::getY3() { return this->y3; }
void Polygon::setY3(int y3) { this->y3 = y3; }

int Polygon::getX4() { return this->x4; }
void Polygon::setX4(int x4) { this->x4 = x4; }
int Polygon::getY4() { return this->y4; }
void Polygon::setY4(int y4) { this->y4 = y4; }
