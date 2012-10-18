/**
 * @file	main.cpp
 * @brief	Entry point
 */

#include <stdio.h>
#include "lib.h"

void main(void)
{
	printf("Enter number of points\n");
	UI pointsNumb;
	if (!scanf("%u", &pointsNumb))
	{
		printf("Incorrect format of input data\n");
		return;
	}
	printf("\nEnter %u point(s) (x, y, z)...\n", pointsNumb);
	Point *pointsSeq = new Point[pointsNumb];
	UI i, j;
	for (i = 0; i < pointsNumb; ++i)
	{
		if (scanf("%f %f %f", &pointsSeq[i].x, &pointsSeq[i].y, &pointsSeq[i].z) < 3)
		{
			printf("Incorrect format of input data\n");
			delete[] pointsSeq;
			return;
		}
	}
	Sort(pointsSeq, pointsNumb);
	printf("\nSorted sequence:\n");
	for (i = 0; i < pointsNumb; ++i)
		printf("%.1f\t%.1f\t%.1f\n", pointsSeq[i].x, pointsSeq[i].y, pointsSeq[i].z);
	printf("\n\nThe two nearest points:\n");
	if (pointsNumb >= 2)
	{
		Point pt1 = *pointsSeq, pt2 = *(pointsSeq + 1);
		double minDist = Dist(pt1, pt2);
		double tempDist;
		for (i = 0; i < pointsNumb; i++)
		{
			for (j = i + 1; j < pointsNumb; j++)
			{
				tempDist = Dist(*(pointsSeq + i), *(pointsSeq + j) );
				if (tempDist < minDist )
				{
					pt1 = *(pointsSeq + i);
					pt2 = *(pointsSeq + j);
					minDist = tempDist;
				}
			}
		}
		printf("1st point (%.1f, %.1f, %.1f), 2nd point (%.1f, %.1f, %.1f)\nDistance: %.1f\n\n", 
			pt1.x, pt1.y, pt1.z, pt2.x, pt2.y, pt2.z, minDist);
	}
	else
	{
		printf("It was entered only one point\n\n");
	}
	delete[] pointsSeq;
}