/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:36:54 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/11 09:41:09 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
	this->setType("WrongCat");
	std::cout << this->getType() << " default constructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat &obj): WrongAnimal()
{
	*this = obj;
	std::cout << this->getType() << " copy constructor called" << std::endl;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << this->getType() << " destructor called" << std::endl;
	return ;
}

WrongCat&	WrongCat::operator=(const WrongCat &obj)
{
	if (this == &obj)
		return (*this);
	this->setType(obj.getType());
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "<\033[3msomeone meaowing\033[0m>" << std::endl;
	return ;
}
