#pragma once
#ifndef Point_H
#define Point_H

#include "Circle.h"

class Point
{
	friend class Circle;

public:
	Point();
	Point(double dx, double dy);
	Point(Point &pcOther);
	void vSetPoint(double dx, double dy);
	double dGetX();
	double dGetY();
	double dGetDistance(double dx, double dy);
	double dGetDistance(Point cPoint);
	double dGetDistance(double dx, double dy, double dr);
	double dGetDistance(Circle cCircle);

private:
	double dx, dy;
};

#endif // Point_H#pragma once
