/**
 * @file	main.cpp
 * @brief	Entry point
 */

#include<iostream>
#include"list.h"

using namespace std;

int main(void)
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.Print();
	return 0;
}