/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:00:43 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/02 12:01:17 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm ("RRF", 72, 45), _target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj): AForm ("RRF", 72, 45)
{
	*this = obj;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Form " << this->getName() << " is destroyed" << std::endl;
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &obj)
{
	if (this == &obj)
		return (*this);
	this->setSign(obj.getSign());
	this->_target = obj.getTarget();
	return (*this);
}

std::string		RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void			RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->checkReq(executor);
	std::cout << "\033[1mdrrrrrrrrr...\033[0m" << std::endl;
	srand(time(NULL));
	if (rand() % 100 < 50)
		std::cout << this->_target << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomy has been failed, rest in pieces dear " << this->_target << std::endl;
}
