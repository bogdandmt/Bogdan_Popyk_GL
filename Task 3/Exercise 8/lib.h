/**
 * @file  lib.h
 * @brief  Prototypes of functions for task 3 exercise 8
 */

#include <stdio.h>
#include <stdlib.h>

#define ROWS_COLS_MIN  1		/* minimum number of rows or columns */
#define ROWS_COLS_MAX	255		/* maximum number of rows or columns */
#define CHAR_BUF_SZ	12		/* size of char buffer */

typedef unsigned char Byte;
typedef unsigned short US;

/**
 * @brief	Function swaps elements by number of two vectors of integers
 * @param	[in, out] vector1 The first vector
 * @param	[in, out] vector2 The second vector
 * @param	[in] number Number of swapping elements
 * @return	void
 */
void SwapVecElem(int *vec1, int *vec2, Byte numb);

/**
 * @brief	Function gets from a console number of rows or columns
 * @param	[in, out] chPtr Char buffer
 * @param	[in] msg Message for printing number of what is entering (number of rows or columns)
 * @return	Byte Number of rows or columns
 */
Byte EnterRowsColsNumb(char *chPtr, const char *msg);

/**
 * @brief	Function prints the matrix
 * @param	[in] matrix Matrix for printing
 * @param	[in] rowsNumb Number of rows in matrix
 * @param	[in] colsNumb Number of columns in matrix
 * @return	void
 */
void PrintMatrix(const int *matrix, Byte rowsNumb, Byte colsNumb);