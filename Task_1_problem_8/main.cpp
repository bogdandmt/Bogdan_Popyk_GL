#include "func_declar.h"

void main (void)
{
	cout << "Enter unsigned integer\n";
	//Checking of input format
	string str;
	getline (cin, str);
	if (str.empty())
	{
		cout << "Incorrect input format\n";
		return;
	}
	for (int i = 0; i < str.length(); ++i)
	{
		if ( !isdigit(str[i]) )
		{
			cout << "Incorrect input format\n";
			return;
		}
	}

	ULI input, res;
	input = atol (str.c_str());

	cout << "Binary representation of the entered numeric:\n" << DecToBin (input) ;
	res = SetFirstBit (input);
	cout << "\nDecimal representation of result:\n" << res;
	cout << "\nBinary representation of the result:\n" << DecToBin (res) << endl;
}