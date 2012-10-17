/**
 * @file	main.cpp
 * @brief	Entry point
 */

#include <stdio.h>

struct Point
{
	int x, y, z;
};

void Sort(Point *arr, int size);

void main()
{
	printf("Enter the number of points\n");
	int numb;
	scanf("%u", &numb);
	printf("Enter array of points\n");
	Point *pointsArr = new Point[numb];
	int i;
	for (i = 0; i < numb; ++i)
	{
		if (scanf("%d %d %d", &pointsArr[i].x, &pointsArr[i].y, &pointsArr[i].z) < 3)
		{
			printf("Incorrect format of input data\n");
			break;
		}
	}
	Sort(pointsArr, numb);
	printf("Sorted array\n");
	for (i = 0; i < numb; ++i)
		printf("%d\t%d\t%d\n", pointsArr[i].x, pointsArr[i].y, pointsArr[i].z);
}

void Sort(Point *arr, int size)
{
	Point temp;
	int i, j;
	for (i = 1; i < size; i++)
		for (j = 0; j < size - i; j++)
			if ( (arr + j) -> z > (arr + j + 1) -> z)
			{
				temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
}