#include <iostream>
#include <string>

using namespace std;

string DecToBin(const unsigned long int &decNumeric);

// 8.	�������������� ����� ���� ��������, �������� �������, ��� ������� ���������� ����� ���� �����, 
//		� ����� ������������ � 1 ���� ���� �� - � ������� ����������� ��������� (������������� � 0) ��� 
//		�������� ������������ ������� ������ ����� (��������� �������).
unsigned long int SetFirstBit(const unsigned long int &unsgnInt);