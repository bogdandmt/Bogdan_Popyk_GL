#include "func_declar.h"

string DecToBin(const unsigned long int &decNumeric)
{
	unsigned long int decNumericCopy = decNumeric;
	char divRemainder;
	string binStr, tempStr;
	while(decNumericCopy > 0)
	{
		divRemainder = decNumericCopy % 2;
		tempStr = divRemainder + '0';
		binStr.insert(0, tempStr);
		decNumericCopy /= 2;
	}
	return binStr;
}

unsigned long int SetFirstBit(const unsigned long int &unsgnInt)
{
	return (1 << 31) | unsgnInt;
}