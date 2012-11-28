/**
 * @file	list.h
 * @brief	Include file for class "List" (6th task)
 */

#ifndef _LIST_H_
#define _LIST_H_

typedef unsigned short int USI;

template <class T>
struct Item
{
	T data;
	Item<T> *next;
	Item() : data(), next(NULL) {}
	Item(const T &_data) : data(_data), next(NULL) {}
};

template <class T>
class List
{
	Item<T> *begin, *end;
	USI size;
public:
	List();

	USI Size();

	void Print();

	void PushBack(const T &elem);
};

#endif /* _LIST_H_ */