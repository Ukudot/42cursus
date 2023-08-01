/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 08:41:59 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/11 09:22:01 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog(void): Animal()
{
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
