/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:22:44 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/02 08:23:17 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int	main(void)
{
	//const try
	try
	{
		Bureaucrat	bob("Bob", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	//incr try
	try
	{
		Bureaucrat	james("James", 1);
		std::cout << james << std::endl;
		james.incr();
		std::cout << james << std::endl;
		james.decr();
		std::cout << james << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	//decr try
	try
	{
		Bureaucrat	robert("Robert", 150);
		std::cout << robert << std::endl;
		robert.decr();
		std::cout << robert << std::endl;
		robert.incr();
		std::cout << robert << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
