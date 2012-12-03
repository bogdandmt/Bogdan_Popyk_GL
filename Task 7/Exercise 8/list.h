/**
 * @file	list.h
 * @brief	Include file for class "List" (7th task)
 */

#ifndef _LIST_H_
#define _LIST_H_

typedef unsigned short int USI;

template <class T>
struct Item
{
	T data;
	Item<T> *next;
	Item() : data(), next(0) {}
	Item(const T &_data) : data(_data), next(0) {}
};

template <class T>
class List
{
	Item<T> *begin, *end;
	USI size;
public:
	List();

	List(const List<T> &l);

	USI Size() const;

	void Print() const;

	void PushBack(const T &elem);

	void Union(List<T> &l);
};

template <class T>
List<T>::List() : begin(0), end(0), size(0) {}

template <class T>
List<T>::List(const List<T> &l)
{
	if(this != &l && l.Size() && l.begin)
	{
		//Item<T> *i = l.begin;
		////begin = l.begin;
		//Item<T> *j = begin;
		//Item<T> *next;
		//while (i)
		//{
		//	Item<T> tmp(i -> data);
		//	next = &tmp;
		//	j = &tmp;
		//	next = j -> next;
		//}
	}
}

template <class T>
USI List<T>::Size() const
{
	return size;
}

template <class T>
void List<T>::Print() const
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

template <class T>
void Union(List<T> &l)
{
}

#endif /* _LIST_H_ */