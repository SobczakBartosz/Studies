#pragma once
#ifndef Circle_H
#define Circle_H

#include "Point.h"

class Circle
{
	friend class Point;

public:
	Circle();
	Circle(double dx, double dy, double dr);
	Circle(Circle &pcOther);
	void vSetCircle(double dx, double dy, double dr);
	double dGetX();
	double dGetY();
	double dGetR();
	double dGetDistance(double dx, double dy);
	double dGetDistance(Point cPoint);
	double dGetDistance(double dx, double dy, double dr);
	double dGetDistance(Circle cCircle);

private:
	double dx, dy, dr;
};

#endif // Circle_H#pragma once
