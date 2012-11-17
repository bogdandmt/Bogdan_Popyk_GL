/**
 * @file	main.cpp
 * @brief	Entry point
 */

#include "func.h"

int main()
{
	string s;
	char chCont;
	do
	{
		system( "cls" );
		cout << "Please, input data for checking of correctness of brackets format...\n";
		fflush(stdin);
		getline(cin, s);
		Preproc(s);
		if ( Check( s, 0, s.length() ) )
		{
			cout << "Brackets format is CORRECT\n";
		}
		else
		{
			cout << "Brackets format is INCORRECT\n";
		}
		cout << "\nEnter 'Y' to input data again or anything else to exit...\n";
		chCont = getchar();
	}
	while ( ( chCont == 'y' ) || ( chCont == 'Y' ) );
	return 0;
}