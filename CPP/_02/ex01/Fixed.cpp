#include "Fixed.hpp"

const int	Fixed::_fbits = 8;
const int	Fixed::_scalar = 256;

std::ostream&	operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}

Fixed::Fixed(void): _num(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(num << Fixed::_fbits);
	return ;
}

Fixed::Fixed(const float num)
{
	int	tmp;
	float	n_num;

	std::cout << "Float constructor called" << std::endl;
	tmp = (int) roundf(num) << this->_fbits;
	n_num = num - roundf(num);
	tmp += (int) roundf(n_num * Fixed::_scalar);
	this->setRawBits((int) tmp);
	return ;
}

Fixed::Fixed(const Fixed &b)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = b;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed&	Fixed::operator=(const Fixed& b)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (&b == this)
		return (*this);
	this->setRawBits(b.getRawBits());
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_num);
}

void	Fixed::setRawBits(const int raw)
{
	this->_num = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	int	tmp;
	float	num;

	tmp = this->getRawBits();
	num = tmp >> Fixed::_fbits;
	tmp -= ((int) num << Fixed::_fbits);
	num += (float) tmp / Fixed::_scalar;
	return (num);
}

int	Fixed::toInt(void) const
{
	return (this->getRawBits() >> Fixed::_fbits);
}
