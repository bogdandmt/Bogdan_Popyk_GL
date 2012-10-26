/**
 * @file	lib.cpp
 * @brief	Realization of functions for task 3 exercise 8
 */

#include "lib.h"

void SwapVectorsElem(int *vec1, int *vec2, Byte numb)
{
	int temp = *(vec1 + numb);
	*(vec1 + numb) = *(vec2 + numb);
	*(vec2 + numb) = temp;
}