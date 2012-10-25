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
	Byte rowsNumb, columnsNumb;
	US elemNumb;
	bool exit, exit2;
	int iTemp;
	US i, j;
	char *chPtr = new char[12];
	char chContinue;
	do
	{
		printf("Matrix entering...\n\n");
		exit = false;
		do
		{
			printf("\tEnter number of rows <= 255 :\n\t");
			scanf("%4s", chPtr);
			iTemp = atoi(chPtr);
			if (iTemp <= 255 && iTemp >= 1 && *chPtr != '0')
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
			printf("\n\tEnter number of columns <= 255 :\n\t");
			scanf("%4s", chPtr);
			iTemp = atoi(chPtr);
			if (iTemp <= 255 && iTemp >= 1 && *chPtr != '0')
			{
				columnsNumb = iTemp;
				exit = true;
			}
			else
			{
				printf("\n\tIncorrect format of input data. Try again.\n");
			}		
			fflush(stdin);
		}
		while (!exit);

		elemNumb = rowsNumb * columnsNumb;
		printf("\n\tEnter %d integer element(s) of matrix...\n\t", elemNumb);
		matrix = new int[rowsNumb * columnsNumb];
		for (i = 0; i < elemNumb; ++i)
		{
			//scanf( "%d", (matrix + i) );
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
			for (j = 0; j < columnsNumb; ++j)
			{
				printf("%d ", *(matrix + columnsNumb * i + j) );
			}
			printf("\n");
		}
		if (rowsNumb >= 2)
		{
			for (i = 0; i < rowsNumb / 2; ++i)
			{
				for(j = 0; j < columnsNumb; ++j)
				{
					SwapVectorsElements( (matrix + columnsNumb * i), (matrix + columnsNumb * (rowsNumb - i - 1) ), j);
				}
			}
		}
		printf("\nResult matrix\n");
		for (i = 0; i < rowsNumb; ++i)
		{
			printf("\t");
			for (j = 0; j < columnsNumb; ++j)
			{
				printf("%d ", *(matrix + columnsNumb * i + j) );
			}
			printf("\n");
		}
		delete[] matrix;

		printf("\nDo You want enter next matrix?\nEnter 'Y' to continue or anything else to exit...\n");
		fflush(stdin);
		chContinue = getchar();
		printf("\n");
	}
	while ( ( chContinue == 'y' ) || ( chContinue == 'Y' ) );
	delete[] chPtr;

	return 0;
}