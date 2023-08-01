/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:32:58 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/03 14:54:04 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook(void)
{
	this->_n_cont = -1;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::add_cont(void)
{
	std::string	line;

	this->_n_cont++;
	std::cout << "\033[1;94mFirst name:	\033[0m";
	std::getline(std::cin, line);
	if (!std::cin)
	{
		std::cout << "\033[1;92mexit\033[0m" << std::endl;
		exit(0);
	}
	while (!line[0])
	{
		std::cout << "\033[1;91mPlease insert a valid input\033[0m" << std::endl;
		std::cout << "\033[1;94mFirst name:	\033[0m";
		std::getline(std::cin, line);
		if (!std::cin)
		{
			std::cout << "\033[1;92mexit\033[0m" << std::endl;
			exit(0);
		}
	}
	this->_conts[this->_n_cont % 8].set_f_name(line);
	std::cout << "\033[1;94mLast name:	\033[0m";
	std::getline(std::cin, line);
	if (!std::cin)
	{
		std::cout << "\033[1;92mexit\033[0m" << std::endl;
		exit(0);
	}
	while (!line[0])
	{
		std::cout << "\033[1;91mPlease insert a valid input" << std::endl;
		std::cout << "\033[1;94mLast name:	\033[0m";
		std::getline(std::cin, line);
		if (!std::cin)
		{
			std::cout << "\033[1;92mexit\033[0m" << std::endl;
			exit(0);
		}
	}
	this->_conts[this->_n_cont % 8].set_l_name(line);
	std::cout << "\033[1;94mNickname:	\033[0m";
	std::getline(std::cin, line);
	if (!std::cin)
	{
		std::cout << "\033[1;92mexit\033[0m" << std::endl;
		exit(0);
	}
	while (!line[0])
	{
		std::cout << "\033[1;91mPlease insert a valid input" << std::endl;
		std::cout << "\033[1;94mNickname:	\033[0m";
		std::getline(std::cin, line);
		if (!std::cin)
		{
			std::cout << "\033[1;92mexit\033[0m" << std::endl;
			exit(0);
		}
	}
	this->_conts[this->_n_cont % 8].set_n_name(line);
	std::cout << "\033[1;94mPhone number:	\033[0m";
	std::getline(std::cin, line);
	if (!std::cin)
	{
		std::cout << "\033[1;92mexit\033[0m" << std::endl;
		exit(0);
	}
	while (!line[0])
	{
		std::cout << "\033[1;91mPlease insert a valid input\033[0m" << std::endl;
		std::cout << "\033[1;94mPhone number:	\033[0m";
		std::getline(std::cin, line);
		if (!std::cin)
		{
			std::cout << "\033[1;92mexit\033[0m" << std::endl;
			exit(0);
		}
	}
	this->_conts[this->_n_cont % 8].set_phone_n(line);
	std::cout << "\033[1;94mDarkest secret:	\033[0m";
	std::getline(std::cin, line);
	if (!std::cin)
	{
		std::cout << "\033[1;92mexit\033[0m" << std::endl;
		exit(0);
	}
	while (!line[0])
	{
		std::cout << "\033[1;91mPlease insert a valid input\033[0m" << std::endl;
		std::cout << "\033[1;94mDarkest secret:	\033[0m";
		std::getline(std::cin, line);
		if (!std::cin)
		{
			std::cout << "\033[1;92mexit\033[0m" << std::endl;
			exit(0);
		}
	}
	this->_conts[this->_n_cont % 8].set_darkest_secret(line);
	return ;
}

void	PhoneBook::print_padded(std::string line) const
{
	if (line.size() > 10)
	{
		line.resize(9);
		line += ".";
	}
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << line;
	return ;
}

void	PhoneBook::display_cont(void) const
{
	int			n;

	n = 7;
	if (this->_n_cont < 7)
		n = this->_n_cont;
	std::cout << std::endl;
	std::cout << "\033[1;42m*----------------------------------";
	std::cout << "---------*\033[0m" << std::endl;
	std::cout << "\033[1;42m|              PhoneBook Users     ";
	std::cout << "         |\033[0m" << std::endl;
	std::cout << "\033[1;42m*----------------------------------";
	std::cout << "---------*\033[0m" << std::endl;
	for (int i = 0; i <= n; i++)
	{
		std::cout << "\033[1;42m|";
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << (i + 1);
		std::cout << "|";
		this->print_padded(this->_conts[i].get_f_name());
		std::cout << "|";
		this->print_padded(this->_conts[i].get_l_name());
		std::cout << "|";
		this->print_padded(this->_conts[i].get_n_name());
		std::cout << "|\033[0m" << std::endl;
		if (i != n)
		{
			std::cout << "\033[1;42m#~~~~~~~~~~#~~~~~~~~~~#~~~~~~~~~~#";
			std::cout << "~~~~~~~~~~#\033[0m" << std::endl;
		}
	}
	std::cout << "\033[1;42m*----------------------------------";
	std::cout << "---------*\033[0m" << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::display_user(int id) const
{
	std::cout << "\033[1;94mFirst name:	\033[0m";
	std::cout << "\033[3m" << this->_conts[id].get_f_name() << "\033[0m" << std::endl;
	std::cout << "\033[1;94mLast name:	\033[0m";
	std::cout << "\033[3m" << this->_conts[id].get_l_name() << "\033[0m" << std::endl;
	std::cout << "\033[1;94mNickname:	\033[0m";
	std::cout << "\033[3m" << this->_conts[id].get_n_name() << "\033[0m" << std::endl;
	std::cout << "\033[1;94mPhone number:	\033[0m";
	std::cout << "\033[3m" << this->_conts[id].get_phone_n() << "\033[0m" << std::endl;
	std::cout << "\033[1;94mDarkest secret:	\033[0m";
	std::cout << "\033[3m" << this->_conts[id].get_darkest_secret() << "\033[0m" << std::endl;
}

void	PhoneBook::search_cont(void) const
{
	std::string	line;

	if (this->_n_cont == -1)
	{
		std::cout << "\033[1;91mNo user registered\033[0m" << std::endl;
		return ;
	}
	this->display_cont();
	std::cout << "\033[1;95mINSERT A VALID INDEX\033[0m" << std::endl;
	std::cout << "\033[1;36mPBSearch> \033[0m";
	std::getline(std::cin, line);
	if (!std::cin)
	{
		std::cout << "\033[1;92mexit\033[0m" << std::endl;
		exit(0);
	}
	while (line.size() != 1 || line[0] < 49 || line[0] - 49 > this->_n_cont)
	{
		if (!std::cin)
		{
			std::cout << "\033[1;92mexit\033[0m" << std::endl;
			exit(0);
		}
		std::cout << "\033[1;91mInvalid index\033[0m" << std::endl;
		std::cout << "\033[1;36mPBSearch> \033[0m";
		std::getline(std::cin, line);
	}
	std::cout << "\033[1;95mUSER FOUND\033[0m" << std::endl;
	this->display_user(line[0] - 49);
}
