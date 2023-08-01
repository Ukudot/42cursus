/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 08:41:59 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/11 12:25:42 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog(void): Animal()
{
	this->_brain = new Brain();
	this->setType("Dog");
	std::cout << this->getType() << " default constructor called" << std::endl;
	return ;
}

Dog::Dog(const Dog &obj): Animal()
{
	*this = obj;
	std::cout << this->getType() << " copy constructor called" << std::endl;
	return ;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << this->getType() << " destructor called" << std::endl;
	return ;
}

Dog&	Dog::operator=(const Dog &obj)
{
	if (this == &obj)
		return (*this);
	this->setType(obj.getType());
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "<\033[3msomeone barking\033[0m>" << std::endl;
	return ;
}

Brain&	Dog::getBrain(void) const
{
	return (*(this->_brain));
}
