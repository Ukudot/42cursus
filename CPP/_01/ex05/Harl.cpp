/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:54:57 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/17 10:53:48 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

typedef void	(Harl::*fp) (void);

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

	if (level != "DEBUG" && level != "INFO"
			&& level != "WARNING" && level != "ERROR")
	{
		std::cout << "Command not found" << std::endl;
		return ;
	}

	fp		fps[4];

	fps[0] = &Harl::warning;
	fps[1] = &Harl::debug;
	fps[2] = &Harl::error;
	fps[3] = &Harl::info;

	id = level[0] % 10 % 7;
	(this->*fps[id])();
	return ;
}
