/**
 * @file	func.cpp
 * @brief	Realization of functions for 6th task
 */

#include "func.h"

void Preproc(string &str)
{
	UI prev = 0;
	UI next = str.find_first_of(BRACKETS, prev);
	while (next != string::npos)
	{
		str.erase(prev, next - prev);
		++prev;
		next = str.find_first_of(BRACKETS, prev);
	}
	if ( prev < str.length() )
	{
		str.erase(prev);
	}
}

bool Check(const string &str, Byte l, Byte r)
{
	if (r <= l)
	{
		return true;
	}

	for (Byte j = 0; j < 3; ++j)
	{
		char t = -2;
		Byte st = 0;
		for (Byte i = l; i < r; ++i)
		{
			if ( str[i] == BRACKETS[2 * j] )
				if(t == -2)
				{
					t = 1;
					st = i;
				}
				else
				{
					t++;
				}
			if ( str[i] == BRACKETS[2 * j + 1] )
				if (t == -2)
				{
					return false;
				}
				else
				{
					t--;
				}
			if (t == -1)
			{
				return false;
			}

			if (t == 0)
			{
				if ( !Check(str, st + 1, i) )
				{
					return false;
				}
				t = -2;
			}
		}
		if(t > 0)
		{
			return false;
		}
	}
	return true;

}