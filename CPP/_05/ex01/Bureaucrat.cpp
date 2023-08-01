/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:41:10 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/02 08:57:04 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj)
{
	*this = obj;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " << this->getName() << " destructor called" << std::endl;
	return ;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &obj)
{
	if (this == &obj)
		return (*this);
	this->_name = obj.getName();
	this->_grade = obj.getGrade();
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int		Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void		Bureaucrat::incr(void)
{
	if (this->_grade == 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade--;
}

void		Bureaucrat::decr(void)
{
	if (this->_grade == 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade++;
}

void		Bureaucrat::signForm(Form &f)
{
	try
	{
		if (f.beSigned(*this))
			std::cout << this->_name << " signed " << f.getName()<< std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " couldn't signed ";
		std::cout << f.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}
