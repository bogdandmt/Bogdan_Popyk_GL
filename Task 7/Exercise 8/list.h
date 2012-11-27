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
	List() : begin(NULL), end(NULL), size(0) {}

	USI Size();

	void Print();

	void PushBack(const T &elem);
};

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