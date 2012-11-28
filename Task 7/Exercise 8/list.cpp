/**
 * @file	list.cpp
 * @brief	Source file for class "List" (6th task)
 */

#include"list.h"

template <class T>
List<T>::List() : begin(NULL), end(NULL), size(0) {}

template <class T>
USI List<T>::Size()
{
	return size;
}

template <class T>
void List<T>::Print()
{
	Item<T> *i = begin;
	while (i)
	{
		cout << i -> data <<" ";
		i = i -> next;
	}
}

template <class T>
void List<T>::PushBack(const T &elem)
{
	Item<T> *tmp = new Item<T>(elem);
	if (tmp)
	{
		if (begin)
		{
			if (end)
			{
				end -> next = tmp;
				end = tmp;
				++size;
			}
			else
			{
				cout << "NULL pointer\n";
			}
		}
		else
		{
			begin = end = tmp;
			++size;
		}
	}
	else
	{
		cout << "Memory was not allocated\n";
	}
}