/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:35:48 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/11 09:42:52 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = obj;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
	return ;
}

WrongAnimal&				WrongAnimal::operator=(const WrongAnimal &obj)
{
	if (this == &obj)
		return (*this);
	this->setType(obj.getType());
	return (*this);
}

void				WrongAnimal::setType(std::string type)
{
	this->_type = type;
	return ;
}

std::string			WrongAnimal::getType(void) const
{
	return (this->_type);
}

void		WrongAnimal::makeSound(void) const
{
	std::cout << this->getType() << ": ";
	std::cout << "\"\033[1;3mWryyyyyyyyyyyy\033[0m\"" << std::endl;
	return ;
}
