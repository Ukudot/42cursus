/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:10:12 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/08 10:45:13 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

typedef void	(*t_fp) (std::string str);
std::string	ScalarConverter::_imp = "";
int		ScalarConverter::_type = 0;
char		ScalarConverter::_char = 0;
int		ScalarConverter::_int = 0;
double		ScalarConverter::_float = 0;
double		ScalarConverter::_double = 0;
char		ScalarConverter::_sign = '.';

ScalarConverter::ScalarConverter(void)
{
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const &obj)
{
	*this = obj;
	return ;
}

ScalarConverter::~ScalarConverter(void)
{
	return ;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &obj)
{
	if (this == &obj)
		return (*this);
	return (*this);
}

void	ScalarConverter::setVar(void)
{
	ScalarConverter::_imp = "";
	ScalarConverter::_type = 0;
	ScalarConverter::_char = 0;
	ScalarConverter::_int = 0;
	ScalarConverter::_float = 0;
	ScalarConverter::_double = 0;
	ScalarConverter::_sign = '.';
}

bool	ScalarConverter::overflowChar(double n)
{
	if (n > 255 || n < 0)
		return (true);
	return (false);
}

bool	ScalarConverter::overflowInt(std::string str)
{
	int	len;

	len = str.length();
	if (len > 10)
		return (true);
	else if (len == 10)
	{
		if (ScalarConverter::_sign == '-' && str.compare("2147483648") > 0)
			return (true);
		else if (str.compare("2147483647") > 0)
			return (true);
	}
	return (false);
}

bool	ScalarConverter::overflowFloat(std::string str)
{
	double	num;

	num = atof(str.c_str());
	if (num > FLT_MAX)
		return (true);
	return (false);
}

bool	ScalarConverter::overflowDouble(std::string str)
{
	double	num;

	num = atof(str.c_str());
	if (num > DBL_MAX)
		return (true);
	return (false);
}

void	ScalarConverter::convert(std::string str)
{
	t_fp	fp[4];

	fp[0] = &ScalarConverter::intFirst;
	fp[1] = &ScalarConverter::floatFirst;
	fp[2] = &ScalarConverter::doubleFirst;
	fp[3] = &ScalarConverter::charFirst;
	ScalarConverter::setVar();
	ScalarConverter::takeSign(str);
	try
	{
		ScalarConverter::typeDetect(str);
		fp[ScalarConverter::_type] (str);
		ScalarConverter::printThem();
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void	ScalarConverter::specialValues(std::string str)
{
	if (str == "inf" || str == "nan")
		ScalarConverter::_type = 2;
	else if (str == "inff" || str == "nanf")
		ScalarConverter::_type = 1;
}

void	ScalarConverter::takeSign(std::string &str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		ScalarConverter::_sign = str[i++];
	str.erase(0, i);
	if (str.empty())
		ScalarConverter::_type = 3;
}

/*
void	ScalarConverter::trimBlank(std::string &str)
{
	int	len;
	int	i;

	i = 0;
	len = str.length();
	while (i < len && isblank(str))
		i++;
	str.erase(0, i);
	len = str.length();
	i = len;
	while (i >= 0 && isblank(str[i]))
		i--;
	if (i != len)
		str.erase(i + 1, len - i - 1);
}
*/

void	ScalarConverter::typeDetect(std::string &str)
{
	if (str.empty() && ScalarConverter::_sign == '.')
		throw (ScalarConverter::emptyStringException());
	ScalarConverter::specialValues(str);
	if (ScalarConverter::_type)
		return ;
	for (int i = 0; i < (int) str.length(); i++)
	{
		if (str[i] == '.')
			ScalarConverter::_type = ScalarConverter::_type * 4 + 2;
		else if (str[i] == 'f' && i == (int) str.length() - 1 && ScalarConverter::_type == 2)
			ScalarConverter::_type = 1;
		else if (!isdigit(str[i]))
			ScalarConverter::_type = 3 + 3 * i;
		else if (isdigit(str[i]) && ScalarConverter::_type == 3)
			ScalarConverter::_type = 3 + 3 * i;
	}
	if (ScalarConverter::_type > 3)
		throw (ScalarConverter::impossibleConversion());
	if (!ScalarConverter::_type && ScalarConverter::overflowInt(str))
	{
		ScalarConverter::_imp += "i";
		ScalarConverter::_type = 1;
	}
	if (ScalarConverter::_type == 1 && ScalarConverter::overflowFloat(str))
	{
		ScalarConverter::_imp += "f";
		ScalarConverter::_type = 2;
	}
	if (ScalarConverter::_type == 2 && ScalarConverter::overflowDouble(str))
	{
		ScalarConverter::_imp += "d";
		ScalarConverter::_type = 4;
	}
}

void	ScalarConverter::charFirst(std::string str)
{
	if (ScalarConverter::_sign != '.')
		ScalarConverter::_char = ScalarConverter::_sign;
	else
		ScalarConverter::_char = str[0];
	ScalarConverter::_int = static_cast <int> (ScalarConverter::_char);
	ScalarConverter::_float = static_cast <float> (ScalarConverter::_char);
	ScalarConverter::_double = static_cast <double> (ScalarConverter::_char);
}

void	ScalarConverter::intFirst(std::string str)
{
	if (ScalarConverter::_sign == '-')
		ScalarConverter::_int = (-1) * atoi(str.c_str());
	else
		ScalarConverter::_int = atoi(str.c_str());
	if (!ScalarConverter::overflowChar(ScalarConverter::_int))
		ScalarConverter::_char = static_cast <char> (ScalarConverter::_int);
	else
		ScalarConverter::_imp += "c";
	ScalarConverter::_float = static_cast <float> (ScalarConverter::_int);
	ScalarConverter::_double = static_cast <double> (ScalarConverter::_int);
}

void	ScalarConverter::floatFirst(std::string str)
{
	if (ScalarConverter::_sign == '-')
		ScalarConverter::_float = (-1) * atof(str.c_str());
	else
		ScalarConverter::_float = atof(str.c_str());
	if (!ScalarConverter::overflowChar(ScalarConverter::_float))
		ScalarConverter::_char = static_cast <char> (ScalarConverter::_float);
	else
		ScalarConverter::_imp += "c";
	if (ScalarConverter::_float > 2147483647 || ScalarConverter::_float < -2147483648)
		ScalarConverter::_imp += "i";
	else
		ScalarConverter::_int = static_cast <int> (ScalarConverter::_float);
	ScalarConverter::_double = static_cast <double> (ScalarConverter::_float);
}

void	ScalarConverter::doubleFirst(std::string str)
{
	if (ScalarConverter::_sign == '-')
		ScalarConverter::_double = (-1) * atof(str.c_str());
	else
		ScalarConverter::_double = atof(str.c_str());
	if (!ScalarConverter::overflowChar(ScalarConverter::_double))
		ScalarConverter::_char = static_cast <char> (ScalarConverter::_double);
	else
		ScalarConverter::_imp += "c";
	if (ScalarConverter::_double > 2147483647 || ScalarConverter::_double < -2147483648)
		ScalarConverter::_imp += "i";
	else
		ScalarConverter::_int = static_cast <int> (ScalarConverter::_double);
	ScalarConverter::_float = static_cast <float> (ScalarConverter::_double);
}

void	ScalarConverter::printThem(void)
{
	std::cout << "char: ";
	if (ScalarConverter::_imp.find("c") != std::string::npos || std::isnan(ScalarConverter::_double))
		std::cout << "impossible";
	else if (!isprint(ScalarConverter::_char))
		std::cout << "not displayabile";
	else
		std::cout << ScalarConverter::_char;
	std::cout << std::endl;
	std::cout << "int: ";
	if (ScalarConverter::_imp.find("i") != std::string::npos || std::isnan(ScalarConverter::_double))
		std::cout << "impossible";
	else
		std::cout << ScalarConverter::_int;
	std::cout << std::endl;
	std::cout << "float: ";
	if (ScalarConverter::_imp.find("f") != std::string::npos)
		std::cout << "impossible";
	else
		std::cout << ScalarConverter::_float << "f";
	std::cout << std::endl;
	std::cout << "double: ";
	if (ScalarConverter::_imp.find("d") != std::string::npos)
		std::cout << "impossible";
	else
		std::cout << ScalarConverter::_double;
	std::cout << std::endl;
}
