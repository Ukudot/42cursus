#ifndef	FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class	Fixed
{
	public:

		Fixed(void);
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &b);
		~Fixed(void);
		Fixed&	operator=(const Fixed &b);
		int	getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int	toInt(void) const;

	private:

		int			_num;
		static const int	_fbits;
		static const int	_scalar;

};

std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif
