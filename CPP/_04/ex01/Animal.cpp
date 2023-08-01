/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 08:27:26 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/11 09:21:06 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): _type("")
{
	std::cout << "Animal default constructor called" << std::endl;
	return ;
}

Animal::Animal(const Animal &obj)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = obj;
	return ;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
	return ;
}

Animal&				Animal::operator=(const Animal &obj)
{
	if (this == &obj)
		return (*this);
	this->setType(obj.getType());
	return (*this);
}

void				Animal::setType(std::string type)
{
	this->_type = type;
	return ;
}

std::string			Animal::getType(void) const
{
	return (this->_type);
}

void		Animal::makeSound(void) const
{
	return ;
}
