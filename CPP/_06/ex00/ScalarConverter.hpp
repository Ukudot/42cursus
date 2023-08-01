/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:48:56 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/06 16:25:38 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <exception>
# include <cstdlib>
# include <cfloat>
# include <cmath>

class	ScalarConverter
{
	private:
		// variables
		static std::string	_imp;
		static int		_type;
		static char		_char;
		static int		_int;
		static double		_float;
		static double		_double;
		static char		_sign;

		// functions
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &obj);
		~ScalarConverter(void);
		ScalarConverter		&operator=(ScalarConverter const &obj);
		static void		setVar(void);
		static bool		overflowChar(double n);
		static bool		overflowInt(std::string str);
		static bool		overflowFloat(std::string str);
		static bool		overflowDouble(std::string str);
		//static void		trimBlank(std::string &str);
		static void		specialValues(std::string str);
		static void		takeSign(std::string &str);
		static void		typeDetect(std::string &str);
		static void		charFirst(std::string str);
		static void		intFirst(std::string str);
		static void		floatFirst(std::string str);
		static void		doubleFirst(std::string str);
		static void		printThem(void);

		// class

		class	emptyStringException: public std::exception
		{
			virtual const char	*what() const throw()
			{
				return ("empty string");
			}
		};
		class	impossibleConversion: public std::exception
		{
			virtual const char	*what() const throw()
			{
				return ("impossible conversion");
			}
		};
	public:
		static void	convert(std::string str);
};

#endif
