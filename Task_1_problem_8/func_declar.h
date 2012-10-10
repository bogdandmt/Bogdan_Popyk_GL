#include <iostream>
#include <string>

using namespace std;

string DecToBin(const unsigned long int &decNumeric);

// 8.	Використовуючи тільки бітові операції, написати функцію, яка повертає беззнакове довге ціле число, 
//		у якому встановлений в 1 лише один біт - у позиції найстаршого очищеного (встановленого в 0) біта 
//		заданого беззнакового довгого цілого числа (параметра функції).
unsigned long int SetFirstBit(const unsigned long int &unsgnInt);