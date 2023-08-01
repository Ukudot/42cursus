/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:55:45 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/03 14:52:31 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(int argc, char *argv[])
{
	std::string	line;
	PhoneBook	phonebook;

	(void) argv;
	if (argc != 1)
	{
		std::cerr << "\033[1;31mUsage error: ./phonebook\033[0m" << std::endl;
		return (1);
	}
	line = "";
	while (std::cin && line != "EXIT")
	{
		std::cout << "\033[1;36mPhoneBook> \033[0m";
		std::getline(std::cin, line);
		if (line == "ADD")
			phonebook.add_cont();
		else if (line == "SEARCH")
			phonebook.search_cont();
		else if (std::cin && line != "EXIT")
			std::cout << "\033[1;91minvalid command\033[0m" << std::endl;
	}
		std::cout << "\033[1;92mexit\033[0m" << std::endl;
	return (0);
}
