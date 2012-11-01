/**
 * @file	main.cpp
 * @brief	Entry point
 */

#include "lib.h"

int main(void)
{
	int *matrix;
	Byte rowsNumb, colsNumb;
	US elemNumb;
	bool exit;
	int iTemp;
	US i, j;
	char *chPtr = new char[CHAR_BUF_SZ];
	char chCont;
	do
	{
		printf("Matrix entering...\n\n");
		rowsNumb = EnterRowsColsNumb(chPtr, "rows");
		colsNumb = EnterRowsColsNumb(chPtr, "columns");

		elemNumb = rowsNumb * colsNumb;
		printf("\n\tEnter %d integer element(s) of matrix...\n\t", elemNumb);
		matrix = new int[rowsNumb * colsNumb];
		for (i = 0; i < elemNumb; ++i)
		{
			exit = false;
			do
			{
				scanf("%11s", chPtr);
				iTemp = atoi(chPtr);
				if ( iTemp != 0 || (iTemp == 0 && *chPtr == '0') )
				{
					exit = true;
				}
				else
				{
					printf("\n\tIncorrect format of input data.\n");
				}		
			}
			while (!exit);
			*(matrix + i) = iTemp;
		}

		printf("\nEntered matrix\n");
		PrintMatrix(matrix, rowsNumb, colsNumb);

		if (rowsNumb >= 2)
		{
			for (i = 0; i < rowsNumb / 2; ++i)
			{
				for(j = 0; j < colsNumb; ++j)
				{
					SwapVecElem( (matrix + colsNumb * i), (matrix + colsNumb * (rowsNumb - i - 1) ), j);
				}
			}
		}

		printf("\nResult matrix\n");
		PrintMatrix(matrix, rowsNumb, colsNumb);

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