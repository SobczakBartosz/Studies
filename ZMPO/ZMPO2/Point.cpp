#include "Point.h"
#include <cmath>

Point::Point()
{
	dx = 0;
	dy = 0;
}

Point::Point(double dx, double dy)
{
	this->dx = dx;
	this->dy = dy;
}

Point::Point(Point &pcOther)
{
	dx = pcOther.dx;
	dy = pcOther.dy;
}

void Point::vSetPoint(double dx, double dy)
{
	this->dx = dx;
	this->dy = dy;
}

double Point::dGetX()
{
	return dx;
}

double Point::dGetY()
{
	return dy;
}

double Point::dGetDistance(double dx, double dy)
{
	double dXDistance = this->dx - dx;
	double dYyDistance = this->dy - dy;
	return sqrt(dXDistance * dXDistance + dYyDistance * dYyDistance);
}

double Point::dGetDistance(Point cPoint)
{
	double dXDistance = this->dx - cPoint.dx;
	double dYyDistance = this->dy - cPoint.dy;
	return sqrt(dXDistance * dXDistance + dYyDistance * dYyDistance);
}

double Point::dGetDistance(double dx, double dy, double dr)
{
	double dXDistance = this->dx - dx;
	double dYyDistance = this->dy - dy;
	return sqrt(dXDistance * dXDistance + dYyDistance * dYyDistance) - dr;
}

double Point::dGetDistance(Circle cCircle)
{
	double dXDistance = this->dx - cCircle.dx;										//cCircle.dGetX()
	double dYyDistance = this->dy - cCircle.dy;										//cCircle.dGetY()
	return sqrt(dXDistance * dXDistance + dYyDistance * dYyDistance) - cCircle.dr;	//cCircle.dGetR()
}