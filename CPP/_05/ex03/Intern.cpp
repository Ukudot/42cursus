/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:19:44 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/02 12:59:23 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
	std::cout << "Intern constructor called" << std::endl;
	return ;
}

Intern::Intern(Intern const &obj)
{
	*this = obj;
	return ;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
	return ;
}

Intern	&Intern::operator=(Intern const &obj)
{
	if (this == &obj)
		return (*this);
	return (*this);
}

void	Intern::checkForm(std::string name) const 
{
	if (name != "shubbery creation" && name != "robotomy request" && name != "presidential pardon")
		throw (Intern::RequestNotExistException());
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	AForm	*form;

	form = 0;
	try
	{
		this->checkForm(name);
		std::cout << "--------" << name[0] % 10 << std::endl;
		switch (name[0] % 10)
		{
			case 2:
				form = new PresidentialPardonForm(target);
				break;
			case 4:
				form = new RobotomyRequestForm(target);
				break;
			case 5:
				form = new ShrubberyCreationForm(target);
				break;
			default: {}
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Invalid operation: " << e.what() << std::endl;
	}
	return (form);
}
