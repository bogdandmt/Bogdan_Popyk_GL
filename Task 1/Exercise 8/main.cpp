/**
 * @file	main.cpp
 * @brief	Entry point
 */

#include <iostream>
#include <string>
#include "../func.h"

using namespace std;

void main (void)
{
	string inputStr;
	cout << "Enter unsigned integer\n";
	getline (cin, inputStr);
	if ( !CheckFormat (inputStr) )
	{
		return;
	}

	ULI input, res;
	input = atol( inputStr.c_str () );

	cout << "Binary representation of the entered numeric:\n" << DecToBin (input) ;
	res = SetFirstBit (input);
	cout << "\nDecimal representation of result:\n" << res;
	cout << "\nBinary representation of the result:\n" << DecToBin (res) << endl;
}