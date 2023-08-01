#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point	p_1(a), p_2(b), p_3(c), p(point);
	Fixed	i = 0;

	p_1.angularCoef(p_2);
	p_1.inter();
	p_2.angularCoef(p_3);
	p_2.inter();
	p_3.angularCoef(p_1);
	p_3.inter();

	if (p_1 < p_3)
	{
		if (p_1 < p)
			i = i + 1;
	}
	else
	{
		if (p_1 > p)
			i = i + 1;
	}
	if (p_2 < p_1)
	{
		if (p_2 < p)
			i = i + 1;
	}
	else
	{
		if (p_2 > p)
			i = i + 1;
	}
	if (p_3 < p_2)
	{
		if (p_3 < p)
			i = i + 1;
	}
	else
	{
		if (p_3 > p)
			i = i + 1;
	}

	if (i == 3)
		return (true);
	return (false);
}
