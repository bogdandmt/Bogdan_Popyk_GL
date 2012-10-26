/**
 * @file  lib.h
 * @brief  Prototypes of functions for task 3 exercise 8
 */

#define ROWS_MIN	1		/* minimum number of rows */
#define ROWS_MAX	255		/* maximum number of rows */
#define COLS_MIN	1		/* minimum number of columns */
#define COLS_MAX	255		/* maximum number of columns */
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
void SwapVectorsElem(int *vec1, int *vec2, Byte numb);