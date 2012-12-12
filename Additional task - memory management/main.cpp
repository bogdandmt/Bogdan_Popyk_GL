/**
 * @file	main.cpp
 * @brief	Entry point
 */

#include "incl.h"

int main(void)
{
	Brand c=ALFA_ROMEO;
	List<Car> l;
	Car car(MERCEDES_BENZ, 10, 2010, 100, "qwerty"),t;
	l.PushBack(car);
	l.PushBack(car);
	l.PushBack(car);

	l.Compact(CAR_SZ);
	cout<<l;

	return 0;
}