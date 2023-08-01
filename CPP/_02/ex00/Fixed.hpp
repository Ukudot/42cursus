#ifndef	FIXED_HPP
# define FIXED_HPP
# include <iostream>

class	Fixed
{
	public:

		Fixed(void);
		Fixed(const Fixed &b);
		~Fixed(void);
		Fixed&	operator=(const Fixed &b);
		int	getRawBits(void) const;
		void	setRawBits(const int raw);

	private:

		int			_num;
		static const int	_fbits;


};

#endif
