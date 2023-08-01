/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:21:46 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/02 08:56:19 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const &name, int const gradeSign, int const gradeExec): _name(name), _signed(false),
	_gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw (Form::GradeTooHighException());
	if (gradeSign > 150 || gradeExec > 150)
		throw (Form::GradeTooLowException());
	return ;
}

Form::Form(Form const &obj): _name(obj.getName()), _gradeSign(obj.getGradeSign()), _gradeExec(obj.getGradeExec())
{
	*this = obj;
	return ;
}

Form::~Form(void)
{
	std::cout << "Form " << this->getName() << " is destroyed" << std::endl;
	return ;
}

Form		&Form::operator=(Form const &obj)
{
	if (this == &obj)
		return (*this);
	this->_signed = obj.getSign();
	return (*this);
}

std::string const	Form::getName(void) const 
{
	return (this->_name);
}

bool			Form::getSign(void) const
{
	return (this->_signed);
}

int			Form::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int			Form::getGradeExec(void) const
{
	return (this->_gradeExec);
}

bool			Form::beSigned(Bureaucrat const &b)
{
	if (this->getSign())
	{
		std::cout << "Form " << this->_name << " is already signed" << std::endl;
		return (false);
	}
	if (this->_gradeSign < b.getGrade())
		throw (Form::GradeTooLowException());
	this->_signed = true;
	return (true);
}

std::ostream		&operator<<(std::ostream &os, Form const &obj)
{
	os << obj.getName() << ", form of grade " << obj.getGradeSign() << std::endl;
	os << "Execution grade: " << obj.getGradeExec() << std::endl;
	return (os);
}
