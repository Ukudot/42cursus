#include "Fixed.hpp"

int main( void )
{
	Fixed	a(4);
	Fixed	b(5.05f);
	Fixed	c(b);
	bool	cond;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;

	std::cout << std::endl;

	std::cout << a << " + " << b << " = " << a + b << std::endl;
	std::cout << a << " - " << b << " = " << a - b << std::endl;
	std::cout << a << " * " << b << " = " << a * b << std::endl;
	std::cout << b << " / " << a << " = " << b / a << std::endl;

	std::cout << std::endl;

	cond = c < b;
	std::cout << c << " < " << b << " = " << cond << std::endl;
	cond = c > b;
	std::cout << c << " > " << b << " = " << cond << std::endl;
	cond = a < b;
	std::cout << a << " < " << b << " = " << cond << std::endl;
	cond = c > a;
	std::cout << c << " > " << a << " = " << cond << std::endl;
	cond = c <= b;
	std::cout << c << " <= " << b << " = " << cond << std::endl;
	cond = c >= b;
	std::cout << c << " >= " << b << " = " << cond << std::endl;
	cond = c == b;
	std::cout << c << " == " << b << " = " << cond << std::endl;
	cond = c == a;
	std::cout << c << " == " << a << " = " << cond << std::endl;
	cond = c != a;
	std::cout << c << " != " << a << " = " << cond << std::endl;
	cond = c != b;
	std::cout << c << " != " << b << " = " << cond << std::endl;

	std::cout << std::endl;

	std::cout << a++ << " a++ " << a << std::endl;
	std::cout << b++ << " b++ " << b << std::endl;
	std::cout << a-- << " a-- " << a << std::endl;
	std::cout << b-- << " b-- " << b << std::endl;

	std::cout << std::endl;

	std::cout << ++a << " ++a " << a << std::endl;
	std::cout << ++b << " ++b " << b << std::endl;
	std::cout << --a << " --a " << a << std::endl;
	std::cout << --b << " --b " << b << std::endl;

	std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;

	return 0;
}
