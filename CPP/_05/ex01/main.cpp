/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:22:44 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/02 08:54:52 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

int	main(void)
{
	//Constructor tries
	std::cout << "\033[1mConstructor errors:\033[0m" << std::endl;
	try
	{
		Form	c12("c12", 0, 132);
	}
	catch (std::exception &e)
	{
		std::cout << "Invalid form operation: " << e.what() << std::endl;
	}
	try
	{
		Form	c12("c12", 13, 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Invalid form operation: " << e.what() << std::endl;
	}
	try
	{
		Form	c12("c12", 1244, 132);
	}
	catch (std::exception &e)
	{
		std::cout << "Invalid form operation: " << e.what() << std::endl;
	}
	try
	{
		Form	c12("c12", 21, 1322);
	}
	catch (std::exception &e)
	{
		std::cout << "Invalid form operation: " << e.what() << std::endl;
	}
	//Sign tests
	Bureaucrat	robert("Robert", 15), james("James", 1), micheal("Micheal", 1);
	Form		c12("C12", 20, 45), r42("R42", 1, 1);

	std::cout << "\033[1m" << robert.getName() << " tries to sign form " << c12.getName() << "\033[0m" << std::endl;
	robert.signForm(c12);
	std::cout << "\033[1m" << robert.getName() << " tries to sign form " << r42.getName() << "\033[0m" << std::endl;
	robert.signForm(r42);
	std::cout << "\033[1m" << james.getName() << " tries to sign form " << r42.getName() << "\033[0m" << std::endl;
	james.signForm(r42);
	
	Form c_r42 = r42;
	
	std::cout << "\033[1m" << micheal.getName() << " tries to sign form " << c_r42.getName() << "\033[0m" << std::endl;
	micheal.signForm(c_r42);

	return (0);
}
