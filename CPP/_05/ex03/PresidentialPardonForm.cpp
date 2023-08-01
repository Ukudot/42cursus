/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:00:08 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/02 12:00:31 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): AForm ("PPF", 25, 5), _target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj): AForm ("PPF", 25, 5)
{
	*this = obj;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Form " << this->getName() << " is destroyed" << std::endl;
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &obj)
{
	if (this == &obj)
		return (*this);
	this->setSign(obj.getSign());
	this->_target = obj.getTarget();
	return (*this);
}

std::string		PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void			PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	this->checkReq(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
