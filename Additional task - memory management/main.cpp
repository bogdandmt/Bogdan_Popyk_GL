/**
 * @file	main.cpp
 * @brief	Entry point
 */

#include "incl.h"

Byte Car::clrFlg = 1;

int main(void)
{
	List<Car> l;
	Car car(MERCEDES_BENZ, 10, 2010, 100, "qwerty");
	Car car2(TOYOTA, 10, 2010, 100, "qwerty2");
	Car car3(MERCEDES_BENZ, 10, 2010, 100, "qwerty3");
	l.PushBack(car);
	l.PushBack(car2);
	l.PushBack(car3);

	l.Print(cout);
	cout<<"\n\n";
	l.Compact();
	l.Print(cout);
	cout<<"\n\n\n";

	l.Diffuse();
	//l.PushBack(car);
	cout << l;

	return 0;
}