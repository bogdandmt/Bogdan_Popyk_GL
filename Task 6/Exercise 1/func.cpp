/**
 * @file	func.cpp
 * @brief	Realization of functions for 6th task
 */

#include "func.h"

void Preproc(string &str)
{
	int prev = 0;
	int next = str.find_first_of(BRACKETS, prev);
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

bool Check(const string &str, int l, int r)
{
	if (r <= l)
	{
		return true;
	}

	for (int j = 0; j < 3; ++j)
	{
		int t = -2;
		int st  = 0;
		for (int i = l; i < r; ++i)
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