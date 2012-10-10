#include "func_declar.h"

void main()
{
	unsigned long int input, res;
	cout << "Input unsigned integer\n";
	cin >> input;
	cout << "Binary representation of the entered numeric:\n" << DecToBin(input);
	res = SetFirstBit(input);
	cout << "\nDecimal representation of result:\n" << res;
	cout << "\nBinary representation of the result:\n" << DecToBin(res) << endl;
}