#include <iostream>
#include <sstream>
#include "Polygon.h"

MyPolygon::MyPolygon(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	if (x1 != x4
		|| x2 != x3
		|| y1 != y2
		|| y3 != y4
		|| x2 <= x1
		|| y3 <= y2)
	{
		throw std::invalid_argument("Wrong polygon coordinates");
	}

	this->x1 = x1;
	this->x2 = x2;
	this->x3 = x3;
	this->x4 = x4;

	this->y1 = y1;
	this->y2 = y2;
	this->y3 = y3;
	this->y4 = y4;
}

MyPolygon& MyPolygon::operator*(const MyPolygon& right_polygon)
{
	if (!(this->hasEqualSide(right_polygon)))
	{
		throw std::invalid_argument("Polygons has no equal sides");
	}

	int newX1 = this->getX1() > right_polygon.x1 ? this->getX1() : right_polygon.x1;
	int newY1 = this->getY1() > right_polygon.y1 ? this->getY1() : right_polygon.y1;
		
	int newX2 = this->getX2() > right_polygon.x2 ? this->getX2() : right_polygon.x2;
	int newY2 = this->getY2() > right_polygon.x2 ? this->getY2() : right_polygon.y2;
	
	int newX3 = this->getX3() > right_polygon.x3 ? this->getX3() : right_polygon.x3;
	int newY3 = this->getY3() > right_polygon.x3 ? this->getY3() : right_polygon.y3;
	
	int newX4 = this->getX4() > right_polygon.x4 ? this->getX4() : right_polygon.x4;
	int newY4 = this->getY4() > right_polygon.x4 ? this->getY4() : right_polygon.y4;

	MyPolygon* polygon = new MyPolygon(newX1, newY1, newX2, newY2, newX2, newY3, newX4, newY4);

	return *polygon;
}

MyPolygon::~MyPolygon()
{
	std::cout << "Destruction of " 
		<< this->getDescription() 
		<< std::endl;
}

string MyPolygon::getDescription()
{
	std::stringstream buffer;

	buffer << "Polygon "
		<< "[" << x1 << ";" << y1 << "],"
		<< "[" << x2 << ";" << y2 << "],"
		<< "[" << x3 << ";" << y3 << "],"
		<< "[" << x4 << ";" << y4 << "]";

	return buffer.str();
}

int MyPolygon::getX1() { return this->x1; }
void MyPolygon::setX1(int x1) { this->x1 = x1; }
int MyPolygon::getY1() { return this->y1; }
void MyPolygon::setY1(int y1) { this->y1 = y1; }

int MyPolygon::getX2() { return this->x2; }
void MyPolygon::setX2(int x2) { this->x2 = x2; }
int MyPolygon::getY2() { return this->y2; }
void MyPolygon::setY2(int y2) { this->y2 = y2; }

int MyPolygon::getX3() { return this->x3; }
void MyPolygon::setX3(int x3) { this->x3 = x3; }
int MyPolygon::getY3() { return this->y3; }
void MyPolygon::setY3(int y3) { this->y3 = y3; }

int MyPolygon::getX4() { return this->x4; }
void MyPolygon::setX4(int x4) { this->x4 = x4; }
int MyPolygon::getY4() { return this->y4; }
void MyPolygon::setY4(int y4) { this->y4 = y4; }

bool MyPolygon::hasEqualSide(const MyPolygon& right_polygon)
{
	const int coordNum = 8;

	int leftPolygonTops[coordNum] = {
		this->getX1(),
		this->getY1(),
		this->getX2(),
		this->getY2(),
		this->getX3(),
		this->getY3(),
		this->getX4(),
		this->getY4() };

	int rightPolygonTops[coordNum] = {
		right_polygon.x1,
		right_polygon.y2,
		right_polygon.x2,
		right_polygon.y2,
		right_polygon.x3,
		right_polygon.y3,
		right_polygon.x4,
		right_polygon.y4};

	for (int i = 0; i < coordNum; i += 2)
	{
		int startX1 = leftPolygonTops[i];
		int startY1 = leftPolygonTops[i + 1];
		int startX2 = leftPolygonTops[(i + 2) % coordNum];
		int startY2 = leftPolygonTops[(i + 3) % coordNum];

		for (int j = 0; j < coordNum; j += 2)
		{
			int endX1 = rightPolygonTops[j];
			int endY1 = rightPolygonTops[j + 1];
			int endX2 = rightPolygonTops[(j + 2) % coordNum];
			int endY2 = rightPolygonTops[(j + 3) % coordNum];

			if ((startX1 == endX1
				&& startY1 == endY1
				&& startX2 == endX2
				&& startY2 == endY2)
				|| (startX1 == endX2
				&& startY1 == endY2
				&& startX2 == endX1
				&& startY2 == endY1))
			{
				return true;
			}
		}

		return false;
	}
}