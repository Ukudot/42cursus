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
	//std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int num)
{
	//std::cout << "Int constructor called" << std::endl;
	this->setRawBits(num << Fixed::_fbits);
	return ;
}

Fixed::Fixed(const float num)
{
	int	tmp;
	float	n_num;

	//std::cout << "Float constructor called" << std::endl;
	tmp = (int) roundf(num) << this->_fbits;
	n_num = num - roundf(num);
	tmp += (int) roundf(n_num * Fixed::_scalar);
	this->setRawBits((int) tmp);
	return ;
}

Fixed::Fixed(const Fixed &b)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = b;
	return ;
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed&	Fixed::operator=(const Fixed& b)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (&b == this)
		return (*this);
	this->setRawBits(b.getRawBits());
	return (*this);
}

bool	Fixed::operator<(const Fixed& b)
{
	if (this->getRawBits() < b.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed& b)
{
	if (this->getRawBits() > b.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& b)
{
	if (this->getRawBits() <= b.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& b)
{
	if (this->getRawBits() >= b.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& b)
{
	if (this->getRawBits() == b.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& b)
{
	if (this->getRawBits() != b.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed& b)
{
	Fixed	result;

	result.setRawBits(this->getRawBits() + b.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed& b)
{
	Fixed	result;
	
	result.setRawBits(this->getRawBits() - b.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed& b)
{
	Fixed	result;
	
	result.setRawBits((int) (((long) this->getRawBits() * (long) b.getRawBits()) >> Fixed::_fbits));
	return (result);
}

Fixed	Fixed::operator/(const Fixed& b)
{
	Fixed	result;

	if (b.getRawBits() == 0)
	{
		std::cout << "Invalid operation" << std::endl;
		exit(1);
	}
	result.setRawBits((int) ((long) this->getRawBits() << Fixed::_fbits) / (long) b.getRawBits());
	return (result);
}

Fixed&	Fixed::operator++()
{
	int	tmp;

	tmp = this->getRawBits();
	this->setRawBits(++tmp);
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	ret;
	int	tmp;

	ret = *this;
	tmp = this->getRawBits();
	this->setRawBits(++tmp);
	return ret;
}

Fixed&	Fixed::operator--()
{
	int	tmp;

	tmp = this->getRawBits();
	this->setRawBits(--tmp);
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	ret;
	int	tmp;

	ret = *this;
	tmp = this->getRawBits();
	this->setRawBits(--tmp);
	return ret;
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

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}
