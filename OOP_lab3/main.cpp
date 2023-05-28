#include <iostream>
#include <string>
#include <Windows.h>
#include "Polygon.h"

#define FIRST_POLYGON_COORDS 1,1,2,1,2,2,1,2

using namespace std;

int main()
{
	MyPolygon* polygon1 = new MyPolygon(FIRST_POLYGON_COORDS);

	delete polygon1;
}