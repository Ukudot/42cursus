/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:24:44 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/15 10:30:29 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage error: ./RPN <expression>" << std::endl;
		return (1);
	}
	try
	{
		RPN::executeOperation(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() <<std::endl;
		return (1);
	}
}
