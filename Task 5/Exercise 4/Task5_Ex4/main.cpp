#include <iostream>
#include <windows.h> 
#include "..\PointInterval\PointInterval.h"

using namespace std;

#define DLL_IMPORT   __declspec (dllimport)

typedef void DLL_IMPORT P(Point *);
P *p1, *p2;

int main(void)
{
	HINSTANCE myDll;
	myDll = LoadLibrary( TEXT("PointInterval.dll") );
	if (myDll)
	{
		/*Point *p;
		p1 = (P*) GetProcAddress(myDll, LPCSTR("GetPoint"));
		if (p1)
		{
			p1(p);
		}
		else cout<<"cant get procAddress\n";

		p2 = (P*) GetProcAddress(myDll, LPCSTR("ShowPoint"));
		if (p2)
		{
			p2(p);
		}
		else cout<<"ShowPoint() "<<"cant get procAddress\n";*/

		void (Point::*ptConstr)();
		(FARPROC &)ptConstr = GetProcAddress( myDll, LPCSTR("??0Point@@QAE@XZ") );

		void (Point::*ptDestr)();
		(FARPROC &)ptDestr = GetProcAddress( myDll, LPCSTR("??1Point@@QAE@XZ") );

		void (Point::*ptParamConstr)(float X, float Y);
		(FARPROC &)ptParamConstr = GetProcAddress( myDll, LPCSTR("??0Point@@QAE@MM@Z") );

		void (Point::*ptPrint)();
		(FARPROC &)ptPrint = GetProcAddress( myDll, LPCSTR("?Print@Point@@QAEXXZ") );

		if (ptConstr)
		{
			char *temp = new char[sizeof(Point)];
			Point *tPoint = (Point*)temp;
			(tPoint ->* ptConstr)();

			(tPoint ->* ptPrint)();

			(tPoint ->* ptDestr)();
			delete[] temp;
		}
		else
		{
			cout<<"Can not get address of the procedure\n";
		} 
		FreeLibrary(myDll); 
	}
	else
	{
		cout<<"Error occurred loading dll\n";
	}

	return 0;
}