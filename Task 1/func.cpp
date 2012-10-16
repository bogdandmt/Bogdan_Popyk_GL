#include <iostream>
#include "func.h"

using namespace std;

const short ULI_BITS = sizeof(ULI) * 8;

bool CheckFormat (string inputStr)
{
	//Checking of input format
	if ( inputStr.empty () )
	{
		cout << "Incorrect input format\n";
		return false;
	}
	for (int i = 0; i < inputStr.length (); ++i)
	{
		if ( !isdigit (inputStr[i]) )
		{
			cout << "Incorrect input format\n";
			return false;
		}
	}
	return true;
}

string DecToBin (const ULI &decNumeric)
{
	ULI decNumericCopy = decNumeric;
	char divRemainder;
	short counter = ULI_BITS;
	string binStr (ULI_BITS, '0');
	while (decNumericCopy > 0)
	{
		divRemainder = decNumericCopy % 2;
		binStr[--counter] = divRemainder + '0';
		decNumericCopy /= 2;
	}
	return binStr;
}

ULI SetFirstBit (const ULI &unsgnInt)
{
	ULI res;
	res = ( unsgnInt | ( unsgnInt >> 1 ) ) ^ unsgnInt;	//Set the bit to "1" in the position of the oldest bit with "0"

	res |= res >> 1;									//All other bits that are right, set to "0"
	res ^= res >> 1;

	res |= res >> 2;
	res ^= res >> 2;

	res |= res >> 3;
	res ^= res >> 3;

	res |= res >> 4;
	res ^= res >> 4;

	res |= res >> 5;
	res ^= res >> 5;

	res |= res >> 6;
	res ^= res >> 6;

	res |= res >> 7;
	res ^= res >> 7;

	res |= res >> 8;
	res ^= res >> 8;

	res |= res >> 9;
	res ^= res >> 9;

	res |= res >> 10;
	res ^= res >> 10;

	res |= res >> 11;
	res ^= res >> 11;

	res |= res >> 12;
	res ^= res >> 12;

	res |= res >> 13;
	res ^= res >> 13;

	res |= res >> 14;
	res ^= res >> 14;

	res |= res >> 15;
	res ^= res >> 15;

	res |= res >> 16;
	res ^= res >> 16;

	res |= res >> 17;
	res ^= res >> 17;

	res |= res >> 18;
	res ^= res >> 18;

	res |= res >> 19;
	res ^= res >> 19;

	res |= res >> 20;
	res ^= res >> 20;

	res |= res >> 21;
	res ^= res >> 21;

	res |= res >> 22;
	res ^= res >> 22;

	res |= res >> 23;
	res ^= res >> 23;

	res |= res >> 24;
	res ^= res >> 24;

	res |= res >> 25;
	res ^= res >> 25;

	res |= res >> 26;
	res ^= res >> 26;

	res |= res >> 27;
	res ^= res >> 27;

	res |= res >> 28;
	res ^= res >> 28;

	res |= res >> 29;
	res ^= res >> 29;

	res |= res >> 30;
	res ^= res >> 30;

	res |= res >> 31;
	res ^= res >> 31;

	return res;
}