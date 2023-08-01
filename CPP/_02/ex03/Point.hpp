#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
	public:

		Point(void);
		Point(float x, float y);
		Point(const Point &point);
		~Point(void);
		Point&		operator=(const Point &point);
		bool		operator>(const Point &point);
		bool		operator<(const Point &point);
		const Fixed	getX(void) const;
		const Fixed	getY(void) const;
		Fixed		getM(void) const;
		void		setM(Fixed m);
		Fixed		getB(void) const;
		void		setB(Fixed b);
		void		setInf(void);
		bool		getInf(void) const;
		void		angularCoef(Point &b);
		void		inter(void);

	private:

		const Fixed	_x;
		const Fixed	_y;
		Fixed		_m;
		Fixed		_b;
		bool		_inf;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
