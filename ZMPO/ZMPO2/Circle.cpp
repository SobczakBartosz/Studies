#include "Circle.h"
#include <cmath>

Circle::Circle()
{
	dx = 0;
	dy = 0;
	dr = 0;
}

Circle::Circle(double dx, double dy, double dr)
{
	this->dx = dx;
	this->dy = dy;
	this->dr = dr;
}

Circle::Circle(Circle &pcOther)
{
	dx = pcOther.dx;
	dy = pcOther.dy;
	dr = pcOther.dr;
}

void Circle::vSetCircle(double dx, double dy, double dr)
{
	this->dx = dx;
	this->dy = dy;
	this->dr = dr;
}

double Circle::dGetX()
{
	return dx;
}

double Circle::dGetY()
{
	return dy;
}

double Circle::dGetR()
{
	return dr;
}

double Circle::dGetDistance(double dx, double dy)
{
	double dXDistance = this->dx - dx;
	double dYyDistance = this->dy - dy;
	return sqrt(dXDistance * dXDistance + dYyDistance * dYyDistance) - dr;
}

double Circle::dGetDistance(Point cPoint)
{
	double dXDistance = this->dx - cPoint.dx;		//cPoint.dGetX()
	double dYyDistance = this->dy - cPoint.dy;		//Point.dGetY()
	return sqrt(dXDistance * dXDistance + dYyDistance * dYyDistance) - this->dr;
}

double Circle::dGetDistance(double dx, double dy, double dr)
{
	double dXDistance = this->dx - dx;
	double dYyDistance = this->dy - dy;
	return sqrt(dXDistance * dXDistance + dYyDistance * dYyDistance) - this->dr - dr;
}

double Circle::dGetDistance(Circle cCircle)
{
	double dXDistance = this->dx - cCircle.dx;
	double dYyDistance = this->dy - cCircle.dy;
	return sqrt(dXDistance * dXDistance + dYyDistance * dYyDistance) - this->dr - cCircle.dr;
}