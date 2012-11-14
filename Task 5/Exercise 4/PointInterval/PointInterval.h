#ifndef _POINTINTERVAL_H_
#define _POINTINTERVAL_H_

#define DLL_EXPORT __declspec (dllexport)
class DLL_EXPORT Point
{
	float x, y;
public:
	Point(void);
	Point(const Point &p) : x(p.x), y(p.y) {}
	Point(float X, float Y);
	~Point(void){}

	void Print(void);
};

class DLL_EXPORT Interval
{
	Point a, b;
public:
	Interval(void);
	Interval(Point A, Point B);
	~Interval(void);
};

extern "C"
{
	DLL_EXPORT void GetPoint(Point *p);
	DLL_EXPORT void ShowPoint(Point *p);
}

#endif	/* _POINTINTERVAL_H_ */