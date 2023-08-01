/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:59:29 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/02 12:04:47 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// ASCII trees

std::string	tree = "       _-_\n\
    /~~   ~~\\\n\
 /~~         ~~\\\n\
{               }\n\
 \\  _-     -_  /\n\
   ~  \\\\ //  ~\n\
_- -   | | _- _\n\
  _ -  | |   -_\n\
      // \\\\\n";

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): AForm ("SCF", 145, 137), _target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj): AForm ("SCF", 145, 137)
{
	*this = obj;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Form " << this->getName() << " is destroyed" << std::endl;
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &obj)
{
	if (this == &obj)
		return (*this);
	this->setSign(obj.getSign());
	this->_target = obj.getTarget();
	return (*this);
}

std::string		ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void			ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::fstream	fs;
	std::string	filename = this->_target + "_shrubbery";

	this->checkReq(executor);
	fs.open(filename.c_str(), std::fstream::out);
	if (fs.is_open())
	{
		for (int i = 0; i < 100; i++)
			fs << tree;
		fs.close();
	}
	else
		std::cout << "Error: cannot open " << filename << std::endl;
}
