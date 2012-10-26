/**
 * @file	main.cpp
 * @brief	Entry point
 */

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(void)
{
	int *matrix;
	Byte rowsNumb, colsNumb;
	US elemNumb;
	bool exit, exit2;
	int iTemp;
	US i, j;
	char *chPtr = new char[CHAR_BUF_SZ];
	char chCont;
	do
	{
		printf("Matrix entering...\n\n");
		exit = false;
		do
		{
			printf("\tEnter number of rows <= %u :\n\t", ROWS_MAX);
			scanf("%4s", chPtr);
			iTemp = atoi(chPtr);
			if (iTemp <= ROWS_MAX && iTemp >= ROWS_MIN && *chPtr != '0')
			{
				rowsNumb = iTemp;
				exit = true;
			}
			else
			{
				printf("\n\tIncorrect format of input data. Try again.\n");
			}		
			fflush(stdin);
		}
		while (!exit);

		exit = false;
		do
		{
			printf("\n\tEnter number of columns <= %u :\n\t", COLS_MAX);
			scanf("%4s", chPtr);
			iTemp = atoi(chPtr);
			if (iTemp <= COLS_MAX && iTemp >= COLS_MIN && *chPtr != '0')
			{
				colsNumb = iTemp;
				exit = true;
			}
			else
			{
				printf("\n\tIncorrect format of input data. Try again.\n");
			}		
			fflush(stdin);
		}
		while (!exit);

		elemNumb = rowsNumb * colsNumb;
		printf("\n\tEnter %d integer element(s) of matrix...\n\t", elemNumb);
		matrix = new int[rowsNumb * colsNumb];
		for (i = 0; i < elemNumb; ++i)
		{
			exit2 = false;
			do
			{
				scanf("%11s", chPtr);
				iTemp = atoi(chPtr);
				if ( iTemp != 0 || (iTemp == 0 && *chPtr == '0') )
				{
					exit2 = true;
				}
				else
				{
					printf("\n\tIncorrect format of input data.\n");
				}		
			}
			while (!exit2);
			*(matrix + i) = iTemp;
		}
		printf("\nEntered matrix\n");
		for (i = 0; i < rowsNumb; ++i)
		{
			printf("\t");
			for (j = 0; j < colsNumb; ++j)
			{
				printf("%d ", *(matrix + colsNumb * i + j) );
			}
			printf("\n");
		}
		if (rowsNumb >= 2)
		{
			for (i = 0; i < rowsNumb / 2; ++i)
			{
				for(j = 0; j < colsNumb; ++j)
				{
					SwapVectorsElem( (matrix + colsNumb * i), (matrix + colsNumb * (rowsNumb - i - 1) ), j);
				}
			}
		}
		printf("\nResult matrix\n");
		for (i = 0; i < rowsNumb; ++i)
		{
			printf("\t");
			for (j = 0; j < colsNumb; ++j)
			{
				printf("%d ", *(matrix + colsNumb * i + j) );
			}
			printf("\n");
		}
		delete[] matrix;

		printf("\nDo You want enter next matrix?\nEnter 'Y' to continue or anything else to exit...\n");
		fflush(stdin);
		chCont = getchar();
		printf("\n");
	}
	while ( ( chCont == 'y' ) || ( chCont == 'Y' ) );
	delete[] chPtr;

	return 0;
}