/**
 * @file	main.cpp
 * @brief	Entry point
 */

#include "incl.h"
#include <list>

int main(void)
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.Print(cout);
	List<int> l3, l2(l);
	l2=l3;
	l2=l;
	l.PushBack(3);

	cout<<endl;
	l2.Print(cout);
	cout<<endl;
	l.Print(cout);
	cout<<endl<<l2.Size()<<"\n\n<<\n";
	cout<<l;

	//Item<int> i1(2);
	//Item<int> i2(i1);
	////i2=i1;
	//cout<<i2.data;

	//Item<int> i(4);
	//const Item<int> &r= 5;
	//Item<int> j(r);
	//cout<<j.data;
	//const Item<int> z(6);
	//Item<int> i=z;

	list<int> stl;
	//stl.pu
	return 0;
}