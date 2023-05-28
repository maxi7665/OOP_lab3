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

	int newX1 = this->getX1() < right_polygon.x1 ? this->getX1() : right_polygon.x1;
	int newY1 = this->getY1() < right_polygon.y1 ? this->getY1() : right_polygon.y1;
		
	int newX2 = this->getX2() > right_polygon.x2 ? this->getX2() : right_polygon.x2;
	int newY2 = this->getY2() < right_polygon.x2 ? this->getY2() : right_polygon.y2;
	
	int newX3 = this->getX3() > right_polygon.x3 ? this->getX3() : right_polygon.x3;
	int newY3 = this->getY3() > right_polygon.x3 ? this->getY3() : right_polygon.y3;
	
	int newX4 = this->getX4() < right_polygon.x4 ? this->getX4() : right_polygon.x4;
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

string MyPolygon::getDescription() const
{
	std::stringstream buffer;

	buffer << "Polygon "
		<< "[" << x1 << ";" << y1 << "],"
		<< "[" << x2 << ";" << y2 << "],"
		<< "[" << x3 << ";" << y3 << "],"
		<< "[" << x4 << ";" << y4 << "]";

	return buffer.str();
}

int MyPolygon::getPerimeter() const
{
	const int coordNum = 8;

	int polygonTops[coordNum] = {
		this->getX1(),
		this->getY1(),
		this->getX2(),
		this->getY2(),
		this->getX3(),
		this->getY3(),
		this->getX4(),
		this->getY4() };

	int perimeter = 0;

	for (int i = 0; i < coordNum; i += 2)
	{
		int x1 = polygonTops[i];
		int y1 = polygonTops[i + 1];
		int x2 = polygonTops[(i + 2) % coordNum];
		int y2 = polygonTops[(i + 3) % coordNum];

		if (x1 != x2)
		{
			perimeter += x1 > x2 ? x1 - x2 : x2 - x1;
		}
		else
		{
			perimeter += y1 > y2 ? y1 - y2 : y2 - y1;
		}
	}

	return perimeter;
}

int MyPolygon::getX1() const { return this->x1; }
void MyPolygon::setX1(int x1) { this->x1 = x1; }
int MyPolygon::getY1() const { return this->y1; }
void MyPolygon::setY1(int y1) { this->y1 = y1; }

int MyPolygon::getX2() const { return this->x2; }
void MyPolygon::setX2(int x2) { this->x2 = x2; }
int MyPolygon::getY2() const { return this->y2; }
void MyPolygon::setY2(int y2) { this->y2 = y2; }

int MyPolygon::getX3() const { return this->x3; }
void MyPolygon::setX3(int x3) { this->x3 = x3; }
int MyPolygon::getY3() const { return this->y3; }
void MyPolygon::setY3(int y3) { this->y3 = y3; }

int MyPolygon::getX4() const { return this->x4; }
void MyPolygon::setX4(int x4) { this->x4 = x4; }
int MyPolygon::getY4() const { return this->y4; }
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
		right_polygon.getX1(),
		right_polygon.getY2(),
		right_polygon.getX2(),
		right_polygon.getY2(),
		right_polygon.getX3(),
		right_polygon.getY3(),
		right_polygon.getX4(),
		right_polygon.getY4()};

	for (int i = 0; i < coordNum; i += 2)
	{
		int leftX1 = leftPolygonTops[i];
		int leftY1 = leftPolygonTops[i + 1];
		int leftX2 = leftPolygonTops[(i + 2) % coordNum];
		int leftY2 = leftPolygonTops[(i + 3) % coordNum];

		for (int j = 0; j < coordNum; j += 2)
		{
			int rightX1 = rightPolygonTops[j];
			int rightY1 = rightPolygonTops[j + 1];
			int rightX2 = rightPolygonTops[(j + 2) % coordNum];
			int rightY2 = rightPolygonTops[(j + 3) % coordNum];

			if ((leftX1 == rightX1
				&& leftY1 == rightY1
				&& leftX2 == rightX2
				&& leftY2 == rightY2)
				|| (leftX1 == rightX2
				&& leftY1 == rightY2
				&& leftX2 == rightX1
				&& leftY2 == rightY1))
			{
				return true;
			}
		}		
	}

	return false;
}

bool operator==(const MyPolygon& left_polygon, const MyPolygon& right_polygon)
{
	return left_polygon.getPerimeter() == right_polygon.getPerimeter();
}
