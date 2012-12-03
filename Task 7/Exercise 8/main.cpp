/**
 * @file	main.cpp
 * @brief	Entry point
 */

#include "incl.h"

int main(void)
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.Print();
	List<int> l2(l);
	//l2.Print();
	return 0;
}