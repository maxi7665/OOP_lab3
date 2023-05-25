#include <string>

using namespace std;

class Polygon
{
private:

	int x1;
	int y1;

	int x2;
	int y2;

	int x3;
	int y3;

	int x4;
	int y4;

public:

	Polygon(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

	Polygon operator *(const Polygon& right_polygon);

	friend bool operator ==(const Polygon & left_polygon, const Polygon & right_polygon);

	bool hasEqualSide(const Polygon& right_polygon);

	int getX1();
	void setX1(int x1);

	int getY1();
	void setY1(int y1);

	int getX2();
	void setX2(int x2);

	int getY2();
	void setY2(int y2);

	int getX3();
	void setX3(int x3);

	int getY3();
	void setY3(int y3);

	int getX4();
	void setX4(int x4);

	int getY4();
	void setY4(int y4);

	~Polygon();	
};