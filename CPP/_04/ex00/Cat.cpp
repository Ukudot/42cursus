/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 08:53:50 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/11 09:21:45 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat(void): Animal()
{
	this->setType("Cat");
	std::cout << this->getType() << " default constructor called" << std::endl;
	return ;
}

Cat::Cat(const Cat &obj): Animal()
{
	*this = obj;
	std::cout << this->getType() << " copy constructor called" << std::endl;
	return ;
}

Cat::~Cat(void)
{
	std::cout << this->getType() << " destructor called" << std::endl;
	return ;
}

Cat&	Cat::operator=(const Cat &obj)
{
	if (this == &obj)
		return (*this);
	this->setType(obj.getType());
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "<\033[3msomeone meaowing\033[0m>" << std::endl;
	return ;
}
