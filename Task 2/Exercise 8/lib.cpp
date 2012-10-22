/**
 * @file	func.cpp
 * @brief	Realization of functions for task 2 exercise 8
 */

#include <cmath>
#include "lib.h"

void Sort(Point *seq, const UI &size)	//Bubble sort
{
	Point temp;
	int i, j;
	for (i = 1; i < size; i++)
		for (j = 0; j < size - i; j++)
			if ( (seq + j) -> z > (seq + j + 1) -> z)
			{
				temp = *(seq + j);
				*(seq + j) = *(seq + j + 1);
				*(seq + j + 1) = temp;
			}
}

float Dist(const Point &p1, const Point &p2)
{
	return sqrt( (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z) );
}