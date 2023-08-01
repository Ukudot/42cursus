/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:27:16 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/11 11:43:51 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
		this->setIdea("no idea", i);
	std::cout << "Brain default constructor called" << std::endl;
	return ;
}

Brain::Brain(const Brain& obj)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = obj;
	return ;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

Brain&		Brain::operator=(const Brain& obj)
{
	if (this == &obj)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->setIdea(obj.getIdea(i), i);
	return (*this);
}

void		Brain::setIdea(std::string idea, int i)
{
	this->_ideas[i] = idea;
	return ;
}

std::string	Brain::getIdea(int i) const
{
	return (this->_ideas[i]);
}
