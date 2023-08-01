/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:54:57 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/17 09:41:21 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	int	id;

	if (level != "ERROR" && level != "WARNING"
			&& level != "INFO" && level != "DEBUG")
	{
			std::cout << "[\033[1;91m<3\033[0m]" << std::endl;
			return ;
	}
	id = level[0] % 10 % 7;
	switch (id)
	{
		case 1:
		{
			std::cout << "[DEBUG]" << std::endl;
			this->debug();
			std::cout << "[INFO]" << std::endl;
			this->info();
			std::cout << "[WARNING]" << std::endl;
			this->warning();
			std::cout << "[ERROR]" << std::endl;
			this->error();
		}	break;
		case 3:
		{
			std::cout << "[INFO]" << std::endl;
			this->info();
			std::cout << "[WARNING]" << std::endl;
			this->warning();
			std::cout << "[ERROR]" << std::endl;
			this->error();
		} 	break;
		case 0:
		{
			std::cout << "[WARNING]" << std::endl;
			this->warning();
			std::cout << "[ERROR]" << std::endl;
			this->error();
		}	break;
		case 2:
		{
			std::cout << "[ERROR]" << std::endl;
			this->error();
		}	break;
		default:
			break;
	}
	return ;
}
