/**
 * @file	list.h
 * @brief	Include file for class "List"
 */

#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>

using namespace std;

#define ITEM_SZ sizeof(Item<T>)			//Size of one element type T

typedef unsigned short int USI;

template <class T> 
struct Item
{
	T data;
	Item<T> *next;

	Item() : data(), next(0) {}

	Item(const Item<T> &i) 
	{
		if (this != &i)
		{
			data = i.data;
			next = 0;
		}
	}

	Item(const T &_data) : data(_data), next(0) {}

	~Item()
	{
		next = 0;
	}

	void Clear()
	{
		data.Clear();
	}

	Item<T>& operator=(const Item<T> &i)
	{
		if (this != &i)
		{
			data = i.data;
			next = 0;
		}
		return *this;
	}
};

template <class T> 
class List
{
	Item<T> *begin, *end;
	USI size;

	void CompactClear();

public:
	List() : begin(0), end(0), size(0) {}

	List(const List<T> &l);

	~List();

	List<T>& operator=(const List<T> &l);

	USI Size() const;

	void Print(std::ostream &out) const;

	void PushBack(const T &elem);

	void PopBack();

	void Clear();

	void Compact();

	void Diffuse();
};

template <class T> 
inline List<T>::List(const List<T> &l) : begin(0), end(0), size(0)
{
	if(this != &l && l.Size() && l.begin)
	{
		Item<T> *i = l.begin;
		while (i)
		{
			this->PushBack(i->data);
			i = i->next;
		}
	}
}

template <class T> 
inline List<T>::~List()
{
	if (begin)
	{
		if (abs( (char *)begin->next - (char *)begin ) != ITEM_SZ)
		{
			Item<T> *i = begin, *tmp;
			while (i)
			{
				tmp = i;
				i = i->next;
				delete tmp;	
			}
			begin = end = 0;
			size = 0;
		}
		else
		{
			Item<T> *i = begin;
			while (i)
			{
				i->Clear();
				i = i->next;	
			}
			char* t = (char *)begin;
			delete[] t;
			begin = end = 0;
			size = 0;
		}
	}
}

template <class T> 
inline List<T>& List<T>::operator=(const List<T> &l)
{
	begin = end = 0;
	size = 0;
	if(this != &l && l.Size() && l.begin)
	{
		Item<T> *i = l.begin;
		while (i)
		{
			this->PushBack(i->data);
			i = i->next;
		}
	}
	return *this;
}

template <class T> 
inline USI List<T>::Size() const
{
	return size;
}

template <class T> 
inline void List<T>::Print(std::ostream &out) const
{
	Item<T> *i = begin;
	while (i)
	{
		out << i->data << "\n" << i << "\n\n";
		i = i->next;
	}
}

template <class T> 
inline void List<T>::PushBack(const T &elem)
{
	char *shift;								//Shift used to guarantee noncompact  placement of list elements
	if (begin)
	{
		if (end)
		{
			shift = new char[3];
			Item<T> *tmp = new Item<T>(elem);
			delete[] shift;
			if (tmp)
			{
				end->next = tmp;
				end = tmp;
				++size;
			}
			else
			{
				cout << "ERROR : Memory was not allocated\n";
			}
		}
		else
		{
			cout << "ERROR : NULL pointer\n";
		}
	}
	else
	{
		shift = new char[3];
		Item<T> *tmp = new Item<T>(elem);
		delete[] shift;
		if (tmp)
		{
			begin = end = tmp;
			++size;
		}
		else
		{
			cout << "ERROR : Memory was not allocated\n";
		}
	}	
}

template <class T> 
inline void List<T>::PopBack()
{
	if (end)
	{
		if (begin == end)
		{
			delete begin;
			begin = end = 0;
		}
		else if (begin)
		{
			Item<T> *i = begin;
			while (i->next != end)
			{
				i = i->next;
			}
			i->next = 0;
			delete end;
			end = i;
		}
		--size;
	}
}

template <class T> 
std::ostream& operator << (std::ostream &out, const List<T> &l)
{
	l.Print(out);
	return out;
}

template <class T> 
void inline List<T>::Clear()
{
	if (begin)
	{
		Item<T> *i = begin, *tmp;
		while (i)
		{
			tmp = i;
			i = i->next;
			delete tmp;			
		}
		begin = end = 0;
		size = 0;
	}
}

template <class T> 
void List<T>::Compact()
{	
	//Checking for necessity of list compacting
	if (size >= 2 && abs( (char *)begin->next - (char *)begin ) != ITEM_SZ)
	{
		char *temp = new char[ITEM_SZ * size];			//Place for compact list
		Item<T> *curr = begin;
		for (USI i = 0; i < size; ++i)
		{
			memcpy(temp + i * ITEM_SZ, curr, ITEM_SZ);
			curr = curr->next;
		}
		USI szTmp = size;
		Car::clrFlg = 0;
		this->Clear();									//Clearing of diffused list
		Car::clrFlg = 1;
		begin = (Item<T> *)temp;
		curr = begin;
		for (USI i = 0; i < szTmp; ++i)
		{
			if(i < szTmp - 1)
			{
				curr->next = (Item<T> *)(temp + (i + 1) * ITEM_SZ);
				curr = curr->next;
			}
			else
			{
				curr->next = 0;
				end = curr;
			}		
		}
		size = szTmp;
	}
}

template <class T>
void List<T>::Diffuse()
{
	if (size >= 2 && abs( (char *)begin->next - (char *)begin ) == ITEM_SZ)
	{
		if (begin)
		{
			
			Item<T> *i = begin;
			Item<T> *curr = new Item<T>(*begin);
			Item<T> *tmpBegin = curr;
			while (i)
			{
				Item<T> *tmpNext = 0;
				if (i->next)
				{
					char *shift = new char[3];
					tmpNext = new Item<T>(*i->next);
					delete[] shift;
				}
				else
				{
					end = curr;
				}
				curr->next = tmpNext;
				curr = curr->next;
				i = i->next;
			}
			char *t = (char *)begin;
			begin = tmpBegin;
			delete[] t;
		}
		else
		{
			cout << "ERROR : NULL pointer\n";
		}
	}
}

#endif /* _LIST_H_ */