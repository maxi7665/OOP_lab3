#include <iostream>
#include <string>
#include <Windows.h>
#include "Polygon.h"

#define FIRST_POLYGON_COORDS 1,1,2,1,2,2,1,2
#define SECOND_POLYGON_COORDS 2,1,3,1,3,2,2,2

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "ËÐ ¹3 ÂÀÐÈÀÍÒ 2" << endl << endl;

	MyPolygon* polygon1 = new MyPolygon(FIRST_POLYGON_COORDS);
	MyPolygon* polygon2 = new MyPolygon(SECOND_POLYGON_COORDS);

	MyPolygon* polygon3 = &((*polygon1) * (*polygon2));

	cout << polygon1->getDescription() << " * " 
		<< polygon2->getDescription() << " is "
		<< polygon3->getDescription() << endl << endl;

	cout << "Perimeter of " << polygon1->getDescription() << " is " << polygon1->getPerimeter() << endl;
	cout << "Perimeter of " << polygon2->getDescription() << " is " << polygon2->getPerimeter() << endl;
	cout << "Perimeter of " << polygon3->getDescription() << " is " << polygon3->getPerimeter() << endl;

	cout << endl;

	bool first_equal = (*polygon1) == (*polygon2);
	bool second_equal = (*polygon1) == (*polygon3);

	cout << polygon1->getDescription() << " is equal to " 
		<< polygon2->getDescription() << " : "
		<< first_equal << endl;

	cout << polygon1->getDescription() << " is equal to "
		<< polygon3->getDescription() << " : "
		<< second_equal << endl;

	cout << endl;

	delete polygon1;
	delete polygon2;
	delete polygon3;
}