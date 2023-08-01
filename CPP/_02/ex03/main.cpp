#include "Point.hpp"

int	main(void)
{
	const Point	a(1.0f, 1.0f);
	const Point	b(1.0f, 2.0f);
	const Point	c(3.0f, 1.0f);
	const Point	p(1.01f, 1.3f);

	std::cout << "point a: " << a.getX() << ", " << a.getY() << std::endl;
	std::cout << "point b: " << b.getX() << ", " << b.getY() << std::endl;
	std::cout << "point c: " << c.getX() << ", " << c.getY() << std::endl;
	std::cout << "point p: " << p.getX() << ", " << p.getY() << std::endl;
	
	if (bsp(a, b, c, p))
		std::cout << "p is in abc" << std::endl;
	else
		std::cout << "p isn't in abc" << std::endl;
	return (0);
}
