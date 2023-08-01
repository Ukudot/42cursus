/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 08:29:14 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/01 09:00:38 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

IMateriaSource::~IMateriaSource(void)
{
	return ;
}

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = 0;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &obj)
{
	*this = obj;
	return ;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
	return ;
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &obj)
{
	if (this == &obj)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		delete this->_inventory[i];
		this->_inventory[i] = obj.getInv(i)->clone();
	}
	return (*this);
}

AMateria	*MateriaSource::getInv(int idx) const
{
	return (this->_inventory[idx]);
}

void		MateriaSource::learnMateria(AMateria *m)
{
	int	i;

	if (m == 0)
	{
		std::cout << "NULL isn't a valid materia" << std::endl;
		return ;
	}
	for (i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
			break ;
	}
	if (i == 4)
	{
		std::cout << "No space left in MateriaSource" << std::endl;
		return ;
	}
	this->_inventory[i] = m;
	return ;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	AMateria	*tmp;
	int		i;

	for (i = 0; i < 4; i++)
	{
		tmp = this->_inventory[i];
		if (tmp && tmp->getType() == type)
			break ;
	}
	if (i == 4)
	{
		std::cout << "Materia " << type << " missing" << std::endl;
		return (0);
	}
	return (tmp->clone());
}
