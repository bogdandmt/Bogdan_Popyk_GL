/**
 * @file	lib.cpp
 * @brief	Realization of functions for task 3 exercise 8
 */

#include "lib.h"

void SwapVectorsElements(int *vector1, int *vector2, const Byte &number)
{
	int temp = *(vector1 + number);
	*(vector1 + number) = *(vector2 + number);
	*(vector2 + number) = temp;
}