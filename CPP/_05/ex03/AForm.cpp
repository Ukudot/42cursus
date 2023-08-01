/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:21:46 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/02 12:04:57 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// AForm

AForm::AForm(std::string const &name, int const gradeSign, int const gradeExec): _name(name), _signed(false),
	_gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw (AForm::GradeTooHighException());
	if (gradeSign > 150 || gradeExec > 150)
		throw (AForm::GradeTooLowException());
	return ;
}

AForm::AForm(AForm const &obj): _name(obj.getName()), _gradeSign(obj.getGradeSign()), _gradeExec(obj.getGradeExec())
{
	*this = obj;
	return ;
}

AForm::~AForm(void)
{
	std::cout << "AForm " << this->getName() << " is destroyed" << std::endl;
	return ;
}

AForm		&AForm::operator=(AForm const &obj)
{
	if (this == &obj)
		return (*this);
	this->_signed = obj.getSign();
	return (*this);
}

std::string const	AForm::getName(void) const 
{
	return (this->_name);
}

bool			AForm::getSign(void) const
{
	return (this->_signed);
}

void			AForm::setSign(bool value)
{
	this->_signed = value;
	return ;
}

int			AForm::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int			AForm::getGradeExec(void) const
{
	return (this->_gradeExec);
}

bool			AForm::beSigned(Bureaucrat const &b)
{
	if (this->getSign())
	{
		std::cout << "AForm " << this->_name << " is already signed" << std::endl;
		return (false);
	}
	if (this->_gradeSign < b.getGrade())
		throw (AForm::GradeTooLowException());
	this->_signed = true;
	return (true);
}

void			AForm::checkReq(Bureaucrat const &b) const
{
	if (!this->_signed)
		throw (AForm::NotSignedException());
	else if (b.getGrade() > this->getGradeExec())
		throw (AForm::GradeTooLowException());
}

std::ostream		&operator<<(std::ostream &os, AForm const &obj)
{
	os << obj.getName() << ", form of grade " << obj.getGradeSign();
	os << ", execution grade " << obj.getGradeExec();
	return (os);
}
