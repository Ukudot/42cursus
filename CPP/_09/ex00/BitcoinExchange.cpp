/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:37:10 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/15 09:20:14 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	this->loadFile();
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &obj)
{
	*this = obj;
	return ;
}

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &obj)
{
	if (this == &obj)
		return (*this);
	this->_data_csv = obj._data_csv;
	return (*this);
}

void		BitcoinExchange::loadFile(void)
{
	std::fstream	fs;
	std::string	line;

	fs.open("data/data.csv", std::fstream::in);
	if (fs.is_open())
	{
		std::getline(fs, line);
		while (std::getline(fs, line))
			this->loadLine(line);	
	}
	else
	{
		fs.close();
		throw (BitcoinExchange::ImpossibleReadException());
	}
	fs.close();
}

void		BitcoinExchange::loadLine(std::string line)
{
	unsigned long		comma;
	std::string		date;
	std::string		e_r;

	comma = line.find(",");
	if (comma == std::string::npos)
		throw (BitcoinExchange::BadSyntaxException());
	date = line.substr(0, comma);
	e_r = line.substr(comma + 1, std::string::npos);
	if (!BitcoinExchange::checkDate(date) || !BitcoinExchange::checkERate(e_r))
		throw (BitcoinExchange::InvalidFieldException());
	this->_data_csv.insert(std::pair<std::string, double>(date, atof(e_r.c_str())));
}

bool		BitcoinExchange::checkDate(std::string date)
{
	std::string	field;
	int		year;
	int		month;
	int		day;

	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	field = date.substr(0, 4);
	if (field < "0000" || field > "2024")
		return (false);
	field = date.substr(5, 2);
	if (field < "01" || field > "12")
		return (false);
	field = date.substr(8, 2);
	if (field < "01" || field > "31")
		return (false);
	year = atoi(date.substr(0, 4).c_str());
	month = atoi(date.substr(5, 2).c_str());
	day = atoi(date.substr(8, 2).c_str());
	if (month == 2 && day > 28 + !(year % 4))
		return (false);
	if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
		return (false);
	return (true);
}

bool		BitcoinExchange::checkERate(std::string e_r)
{
	int	len;
	int	cnt;

	len = e_r.length();
	cnt = 0;
	for (int i = 0; i < len; i++)
	{
		if (e_r[i] == '-')
			i++;
		if (!isdigit(e_r[i]) && e_r[i] != '.')
			return (false);
		if (e_r[i] == '.')
			cnt++;
		if (cnt > 1)
			return (false);
	}
	return (true);
}		

void		BitcoinExchange::checkERBounds(std::string e_r)
{
	double	exchangeRate;

	exchangeRate = atof(e_r.c_str());
	if (exchangeRate < 0)
		throw (BitcoinExchange::NegativeRateException());
	if (exchangeRate > 1000)
		throw (BitcoinExchange::LargeRateException());
}

void		BitcoinExchange::readInput(std::string filename)
{
	std::fstream	fs;
	std::string	line;

	fs.open(filename.c_str(), std::fstream::in);
	if (fs.is_open())
	{
		std::getline(fs, line);
		if (line != "date | value")
		{
			fs.close();
			throw (BitcoinExchange::InvalidFileException());
		}
		while (std::getline(fs, line))
		{
			try
			{
				this->inputLine(line);
			}
			catch (std::exception &e)
			{
				std::cout << "Error: " << e.what() << " => " << this->_input << std::endl;
			}
		}
	}
	else
	{
		fs.close();
		throw (BitcoinExchange::ImpossibleReadException());
	}
	fs.close();
}

void		BitcoinExchange::inputLine(std::string line)
{
	std::string		field;
	std::string		date;
	double			e_r;
	unsigned long		pipe;

	this->_input = line;
	pipe = line.find(" | ");
	if (pipe == std::string::npos)
		throw (BitcoinExchange::BadInputException());
	date = line.substr(0, pipe);
	if (!BitcoinExchange::checkDate(date))
		throw (BitcoinExchange::BadInputException());
	field = line.substr(pipe + 3, std::string::npos);
	if (field.length() == 0 || !BitcoinExchange::checkERate(field))
		throw (BitcoinExchange::BadInputException());
	BitcoinExchange::checkERBounds(field);
	e_r = atof(field.c_str());
	this->printOutput(date, e_r);
}

void		BitcoinExchange::printOutput(std::string date, double e_r)
{
	std::map<std::string, double>::iterator	low;
	std::map<std::string, double>::iterator	up;

	low = this->_data_csv.lower_bound(date);
	up = this->_data_csv.upper_bound(date);
	if (low == this->_data_csv.begin())
	{
		std::cout << "not found" << std::endl;
		return ;
	}
	else if (low == up)
		low--;
	std::cout << date << " => " << e_r << " = ";
	std::cout << e_r * low->second << std::endl;
}
