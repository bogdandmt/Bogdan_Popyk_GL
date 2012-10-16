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

	ULI input;
	input = atol( inputStr.c_str () );

	cout << "Binary representation of the entered numeric:\n" << DecToBin (input) ;
	ChangeClearedBit(input);
	cout << "\nDecimal representation of result:\n" << input;
	cout << "\nBinary representation of the result:\n" << DecToBin (input) << endl;
}