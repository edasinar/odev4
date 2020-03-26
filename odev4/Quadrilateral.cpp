#include "Quadrilateral.h"
#include <iostream>
#include <exception>
#include <stdexcept>
//a her zaman sol üst c her zaman sað alt köþe olacak þekilde koordinalarý verdik.


Quadrilateral::Quadrilateral(const Point& a, const Point& c, const Color& color)
{
	pts[0].x = a.x;
	pts[0].y = a.y;

	pts[1].x = c.x;
	pts[1].y = a.y;

	pts[2].x = c.x;
	pts[2].y = c.y;

	pts[3].x = a.x;
	pts[3].y = c.y;

	this->color = color;

	isValid();
}

Quadrilateral::Quadrilateral(const Point& a, double width, double height, const Color& color)
{
	pts[0].x = a.x;
	pts[0].y = a.y;

	pts[1].x = a.x + width;
	pts[1].y = a.y;

	pts[2].x = pts[1].x;
	pts[2].y = a.y + height;

	pts[3].x = a.x;
	pts[3].y = pts[2].y;

	this->color = color;

	isValid();
}

 /*c noktasý her zaman saðda olacaksa c noktasýnýn koordinatlar ab doðru parçasýnýn saðýnda olmalýdýr.
 bu fonksiyonda ab doðru parçasýnýn denklemini bulacaðýz ve c'nin y deðerini denkleme yazaðýz. 
 denklemden bulduðumuz x deðerini c nin x deðeri ile kýyaslayacaðýz. c.x bulduðumuz deðerden büyükse c noktasý 
 doðru parçasýnýn saðýnda kalmýþ olur.*/

Quadrilateral::Quadrilateral(const Point& a, const Point& b, const Point& c, const Point& d, const Color& color)
{
	this->a.x = a.x;
	this->a.y = a.y;

	this->b.x = b.x;
	this->b.y = b.y;

	this->c.x = c.x;
	this->c.y = c.y;

	this->d.x = d.x;
	this->d.y = d.y;

	this->color = color;

	isValid();

}

Quadrilateral::Quadrilateral(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color)
{
	this->pts[0].x = pts[0].x;
	this->pts[0].y = pts[0].y;

	this->pts[1].x = pts[1].x;
	this->pts[1].y = pts[1].y;

	this->pts[2].x = pts[2].x;
	this->pts[2].y = pts[2].y;

	this->pts[3].x = pts[3].x;
	this->pts[3].y = pts[3].y;

	this->color = color;

	isValid();

}

Point Quadrilateral::getA() const noexcept
{
	return a;
}

Point Quadrilateral::getB() const noexcept
{
	return b;
}

Point Quadrilateral::getC() const noexcept
{
	return c;
}

Point Quadrilateral::getD() const noexcept
{
	return d;
}

Quadrilateral::Color Quadrilateral::getColor() const noexcept
{
	return color;
}

string Quadrilateral::getColorAsString() const noexcept
{


	return string();
}

double Quadrilateral::getPerimeter() const noexcept
{
	double k, l, m, n;
	k = a.distanceTo(b);
	l = b.distanceTo(c);
	m = c.distanceTo(d);
	n = d.distanceTo(a);
	
	return (k + l + m + n);
}

bool Quadrilateral::isValid() const
{

	double egim;
	egim = (b.y - a.y) / (b.x - a.x);
	Point_st denklem;
	denklem.y = c.y;
	denklem.x = (denklem.y - a.y) / egim + a.x;
	if (c.x > denklem.x)
	{
		denklem.y = d.y;
		denklem.x = (denklem.y - a.y) / egim + a.x;
		if (d.x <= denklem.x)
		{
			throw invalid_argument("dortgen degildir.");
		}
	}
	else
	{
		throw invalid_argument("dortgen degildir.");
	}

	return false;
}

bool Quadrilateral::setA(const Point& pt)
{
	a.x = pt.x;
	a.y = pt.y;

	isValid();

	return false;
}

bool Quadrilateral::setB(const Point& pt)
{
	b.x = pt.x;
	b.y = pt.y;

	isValid();

	return false;
}

bool Quadrilateral::setC(const Point& pt)
{
	c.x = pt.x;
	c.y = pt.y;

	isValid();

	return false;
}

bool Quadrilateral::setD(const Point& pt)
{
	d.x = pt.x;
	d.y = pt.y;

	isValid();

	return false;
}

double Quadrilateral::printInfo() const noexcept
{
	std::cout << "Quadrilateral:" << endl;
	std::cout << "number of points:" << NUMBER_OF_CORNERS << endl;
	std::cout << "a(" << getA << ") b(" << getB << ") c(" << getC << ") d(" << getD << ")" << endl;
	std::cout << getPerimeter() << endl;
	std::cout << getColorAsString() << endl;
	return 0.0;
}
