#include "Triangle.h"
#include <iostream>
#include <exception>
#include <stdexcept>
#include <cmath>

Triangle::Triangle(const Point& a, const Point& b, const Point& c, const Color& color)
{
	pts[0].x = a.x;
	pts[0].y = a.y;

	pts[1].x = b.x;
	pts[1].y = b.y;

	pts[2].x = c.x;
	pts[2].y = c.y;

	this->color = color;

	isValid();
}

Triangle::Triangle(const vector<Point>& pts, const Color& color)
{
	this->pts[0].x = pts[0].x;
	this->pts[0].y = pts[0].y;

	this->pts[1].x = pts[1].x;
	this->pts[1].y = pts[1].y;

	this->pts[2].x = pts[2].x;
	this->pts[2].y = pts[2].y;

	this->color = color;

	isValid();

}

Triangle::Triangle(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color)
{
	this->pts[0].x = pts[0].x;
	this->pts[0].y = pts[0].y;

	this->pts[0].x = pts[0].x;
	this->pts[0].y = pts[0].y;

	this->pts[0].x = pts[0].x;
	this->pts[0].y = pts[0].y;

	this->color = color;

	isValid();
}

Point Triangle::getA() const noexcept
{
	return a;
}

Point Triangle::getB() const noexcept
{
	return b;
}

Point Triangle::getC() const noexcept
{
	return c;
}

Triangle::Color Triangle::getColor() const noexcept
{
	return color;
}

string Triangle::getColorAsString() const noexcept
{
	return colorTostringMap.at(color);
}

double Triangle::getPerimeter() const noexcept
{
	double k, l, m;
	k = a.distanceTo(b);
	l = b.distanceTo(c);
	m = c.distanceTo(a);
	return (k + l + m);
}

bool Triangle::setA(const Point& pt)
{
	a.x = pt.x;
	a.y = pt.y;

	isValid();

	return false;
}

bool Triangle::setB(const Point& pt)
{
	b.x = pt.x;
	b.y = pt.y;

	isValid();

	return false;
}

bool Triangle::setC(const Point& pt)
{
	c.x = pt.x;
	c.y = pt.y;

	isValid();

	return false;
}

bool Triangle::isValid() const
{
	double x = a.distanceTo(b);
	double y = b.distanceTo(c);
	double z = c.distanceTo(a);
	if (x > (y + z) || x < abs(y - z))
		throw invalid_argument("ucgen degildir.");

	if (y > (x + z) || y < abs(x - z))
		throw invalid_argument("ucgen degildir.");

	if (z > (x + y) || z < abs(x - y))
		throw invalid_argument("ucgen degildir.");

	if ((a.x == b.x) == c.x || (a.y == b.y) == c.y)
		throw invalid_argument("ucgen degildir.");

	double egim= (b.y - a.y) / (b.x - a.x);
	Point_st denklem;
	denklem.y = c.y;
	denklem.x = (denklem.y - a.y) / egim + a.x;
	if (c.x == denklem.x)
		throw invalid_argument("ucgen degildir.");



	return false;
}

double Triangle::printInfo() const noexcept
{
	std::cout << "TRIANGLE:" << endl;
	std::cout << "Number of points:" << NUMBER_OF_CORNERS << endl;
	std::cout << "Points: a(" << getA << ") b(" << getB << ") c(" << getC << ")" << endl;
	std::cout << "Primeter: " << getPerimeter() << endl;
	std::cout << "Color:" << getColorAsString() << endl;

	return 0.0;
}
