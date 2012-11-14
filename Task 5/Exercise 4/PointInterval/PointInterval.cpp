// PointInterval.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

using namespace std;

Point::Point(void) : x(0), y(0) {}

//Point::Point(const Point &p)
//{
//	if (this != &p)
//	{
//		x = p.x;
//		y = p.y;
//	}
//}

Point::Point(float X, float Y) : x(X), y(Y) {}

void Point::Print(void)
{
	cout << x << ' ' << y;
}

Interval::Interval(void) : a(), b() {}

Interval::Interval(Point A, Point B) : a(A), b(B) {}
