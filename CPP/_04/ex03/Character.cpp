/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:01:25 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/01 09:07:15 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

ICharacter::~ICharacter(void)
{
	return ;
}

Character::Character(std::string const &name): _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = 0;
	for (int i = 0; i < 200; i++)
		this->_unequiped[i] = 0;
	return ;
}

Character::Character(const Character &obj)
{
	*this = obj;
	return ;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
	for (int i = 0; this->_unequiped[i]; i++)
		delete this->_unequiped[i];
	return ;
}

Character&		Character::operator=(const Character &obj)
{
	AMateria	*tmp;

	if (this == &obj)
		return (*this);
	this->_name = obj._name;
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
	for (int i = 0; this->_unequiped[i]; i++)
		delete this->_unequiped[i];
	for (int i = 0; i < 4; i++)
	{
		tmp = obj.getInv(i)->clone();
		if (tmp)
			this->_inventory[i] = tmp->clone();
	}
	for (int i = 0; this->_unequiped[i]; i++)
	{
		tmp = obj.getUne(i)->clone();
		if (tmp)
			this->_unequiped[i] = tmp->clone();
	}
	return (*this);
}

AMateria		*Character::getInv(int idx) const
{
	return (this->_inventory[idx]);
}

AMateria		*Character::getUne(int idx) const
{
	return (this->_unequiped[idx]);
}

std::string const	&Character::getName(void) const
{
	return (this->_name);
}

void			Character::equip(AMateria* m)
{
	int	i;

	for (i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			break;
		}
	}
	if ( i == 4)
		std::cout << "The invenotory is full" << std::endl;
	return ;
}

void			Character::unequip(int idx)
{
	int	i = 0;

	if (!this->_inventory[idx])
	{
		std::cout << "Empty slot" << std::endl;
		return ;
	}
	while (i < 200)
	{
		if (!this->_unequiped[i])
			break;
		i++;
	}
	if (i == 200)
		std::cout << "Memory error" << std::endl;
	else
	{
		this->_unequiped[i] = this->_inventory[idx];
		this->_inventory[idx] = 0;
	}
	return ;
}

void			Character::use(int idx, ICharacter &target)
{
	if (!this->_inventory[idx])
	{
		std::cout << "Empty slot" << std::endl;
		return ;
	}
	this->getInv(idx)->use(target);
	this->unequip(idx);
	return ;
}
