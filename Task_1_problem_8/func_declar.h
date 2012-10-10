#include <iostream>
#include <string>

using namespace std;

// Function that converts a decimal representation of the number in binary
string DecToBin(const unsigned long int &decNumeric);

// Problem N8.  Function that returns an unsigned long integer, which is set to 1 only one bit - in the position
//				of the oldest cleared (set to 0) bits set unsigned long integer (function parameter).
unsigned long int SetFirstBit(const unsigned long int &unsgnInt);