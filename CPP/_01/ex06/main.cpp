/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:05:44 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/08 16:07:59 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl		harl;
	std::string	level;

	if (argc != 2)
	{
		std::cout << "Usage Error: ./HarlFilter [command]" << std::endl;
		return (1);
	}
	level = argv[1];
	harl.complain(level);
	return (0);
}
