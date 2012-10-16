/**
 * @file	func.h
 * @brief	Prototypes of functions for 1st task
 */

#include <string>

using namespace std;

typedef unsigned long int ULI;

/**
 * @brief	The function checks format of input data (must be an unsigned number)
 * @param	[in] inputStr Input data
 * @return	bool Is input data in the correct format
 */
bool CheckFormat (const string &inputStr);

/**
 * @brief	Function that converts a decimal number in binary
 * @param	[in] decNumeric Input decimal number
 * @return	string Binary representation of decNumeric
 */
string DecToBin (const ULI &decNumeric);

/**
 * @brief	Function that returns an unsigned long integer, which is set to 1 only one bit - in the position
 *			of the oldest cleared (set to 0) bits set unsigned long integer (function parameter).
 * @param	[in] unsgnInt Input unsigned long integer
 * @remark	Exercise number 8
 * @return	ULI Output unsigned long integer
 */
ULI SetFirstBit (const ULI &unsgnInt);

/**
 * @brief	Function that change the youngest cleared bit to '1'
 * @param	[in, out] unsgnInt Input unsigned long integer to be changed
 * @remark	Exercise number 9
 * @return	void
 */
void ChangeClearedBit (ULI &unsgnInt);