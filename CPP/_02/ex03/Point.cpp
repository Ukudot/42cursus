#include "Point.hpp"

Point::Point(void): _x(Fixed(0)), _y(Fixed(0)), _inf(false)
{
	return ;
}

Point::Point(float x, float y): _x(Fixed(x)), _y(Fixed(y)), _inf(false)
{
	return ;
}

Point::Point(const Point &point): _x(point.getX()), _y(point.getY()), _inf(false)
{
	return ;
}

Point::~Point(void)
{
	return ;
}

Point&		Point::operator=(const Point &point)
{
	if (this == &point)
		return (*this);
	this->_m = point.getM();
	this->_b = point.getB();
	return (*this);
}

bool		Point::operator<(const Point &point)
{
	Fixed	x;
	Fixed	y;
	Fixed	x_t;

	x = point.getX();
	if (this->getInf())
	{
		x_t = this->getX();
		if (x_t < x)
			return (true);
		return (false);
	}
	y = x * this->_m + this->_b;
	if (y < point.getY())
		return (true);
	return (false);
}

bool		Point::operator>(const Point &point)
{
	Fixed	x;
	Fixed	y;
	Fixed	x_t;

	x = point.getX();
	if (this->getInf())
	{
		x_t = this->getX();
		if (x_t > x)
			return (true);
		return (false);
	}
	y = x * this->_m + this->_b;
	if (y > point.getY())
		return (true);
	return (false);
}

const Fixed	Point::getX(void) const
{
	return (this->_x);
}

const Fixed	Point::getY(void) const
{
	return (this->_y);
}

Fixed		Point::getM(void) const
{
	return (this->_m);
}

void		Point::setM(Fixed m)
{
	this->_m = m;
	return ;
}

Fixed		Point::getB(void) const
{
	return (this->_b);
}

void		Point::setB(Fixed b)
{
	this->_b = b;
	return ;
}

void		Point::setInf(void)
{
	this->_inf = true;
	return ;
}

bool		Point::getInf(void) const
{
	return (this->_inf);
}

void		Point::angularCoef(Point &b)
{
	Fixed	m, x_1, x_2, y_1, y_2;

	x_1 = this->getX();
	x_2 = b.getX();
	y_1 = this->getY();
	y_2 = b.getY();
	if ((x_2 - x_1) == 0)
		this->setInf();
	else
	{
		m = ((y_2 - y_1) / (x_2 - x_1));
		this->setM(m);
	}
	return ;
}

void		Point::inter(void)
{
	Fixed	inter, x, y;

	x = this->getX();
	y = this->getY();
	inter = (y - (this->getM() * x));
	this->setB(inter);
	return ;
}
