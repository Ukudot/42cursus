/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:21:46 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/15 09:17:48 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <exception>
# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <stdlib.h>

class	BitcoinExchange
{
	public:
		// functions
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &obj);
		~BitcoinExchange(void);
		BitcoinExchange		&operator=(BitcoinExchange const &obj);
		void			readInput(std::string filename);
	public:
		// class
		class	ImpossibleReadException: public std::exception
		{
			virtual char const *what() const throw()
			{
				return ("cannot read file");
			}
		};
		class	InvalidFileException: public std::exception
		{
			virtual char const *what() const throw()
			{
				return ("invalid input file");
			}
		};
		class	BadSyntaxException: public std::exception
		{
			virtual char const *what() const throw()
			{
				return ("bad syntax in input file");
			}
		};
		class	InvalidFieldException: public std::exception
		{
			virtual char const *what() const throw()
			{
				return ("invalid field in file");
			}
		};
		class	BadInputException: public std::exception
		{
			virtual char const *what() const throw()
			{
				return ("bad input");
			}
		};
		class	NegativeRateException: public std::exception
		{
			virtual char const *what() const throw()
			{
				return ("negative number");
			}
		};
		class	LargeRateException: public std::exception
		{
			virtual char const *what() const throw()
			{
				return ("too large number");
			}
		};
	private:
		// functions
		void			loadFile(void);
		void			loadLine(std::string line);
		void			inputLine(std::string line);
		void			printOutput(std::string line, double e_r);

		// static functions
		static bool		checkDate(std::string date);
		static bool		checkERate(std::string e_r);
		static void		checkERBounds(std::string e_r);
		// variables
		std::map<std::string, double>	_data_csv;
		std::string			_input;
};

#endif
