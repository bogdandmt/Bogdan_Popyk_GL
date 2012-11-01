/**
 * @file	lib.cpp
 * @brief	Realization of functions for task 3 exercise 8
 */

#include "lib.h"

void SwapVecElem(int *vec1, int *vec2, Byte numb)
{
	if(vec1 && vec2)
	{
		int temp = *(vec1 + numb);
		*(vec1 + numb) = *(vec2 + numb);
		*(vec2 + numb) = temp;
	}
	else
	{
		printf("Vector is not valid");
	}
}

Byte EnterRowsColsNumb(char *chPtr, const char *msg)
{
	if (chPtr)
	{
		bool exit = false;
		int iTemp;
		Byte linesNumb;
		do
		{
			printf("\tEnter number of %s <= %u :\n\t", msg, ROWS_COLS_MAX);
			scanf("%4s", chPtr);
			printf("\n");
			iTemp = atoi(chPtr);
			if (iTemp <= ROWS_COLS_MAX && iTemp >= ROWS_COLS_MIN && *chPtr != '0')
			{
				linesNumb = iTemp;
				exit = true;
			}
			else
			{
				printf("\n\tIncorrect format of input data. Try again.\n");
			}		
			fflush(stdin);
		}
		while (!exit);
		return linesNumb;
	}
	else
	{
		printf("Invalid pointer to char\n");
		return 0U;
	}
}

void PrintMatrix(const int *matrix, Byte rowsNumb, Byte colsNumb)
{
	Byte i, j;
	for (i = 0; i < rowsNumb; ++i)
	{
		printf("\t");
		for (j = 0; j < colsNumb; ++j)
		{
			printf("%d\t", *(matrix + colsNumb * i + j) );
		}
		printf("\n");
	}
}