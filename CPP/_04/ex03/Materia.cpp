/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 08:30:04 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/01 08:54:54 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"
#include "Character.hpp"

AMateria::AMateria(std::string const &type): _type(type)
{
	return ;
}

AMateria::AMateria(const AMateria &obj)
{
	*this = obj;
	return ;
}

AMateria::~AMateria(void)
{
	return ;
}

AMateria		&AMateria::operator=(const AMateria &obj)
{
	if (this == &obj)
		return (*this);
	this->_type = obj.getType();
	return(*this);
}

std::string const	&AMateria::getType(void) const
{
	return (this->_type);
}

void			AMateria::use(ICharacter& target)
{
	std::cout << "* Trying to use an unpolished materia at " << target.getName() <<" *" << std::endl;
	std::cout << "* Nothing happens *" << std::endl;
	return ;
}

Ice::Ice(void): AMateria("ice")
{
	return ;
}

Ice::Ice(const Ice &obj): AMateria("ice")
{
	*this = obj;
	return ;
}

Ice::~Ice(void)
{
	return ;
}

Ice			&Ice::operator=(const Ice &obj)
{
	if (this == &obj)
		return (*this);
	return(*this);
}

AMateria		*Ice::clone(void) const
{
	AMateria	*clone;
	clone = new Ice();
	return (clone);
}

void			Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}


Cure::Cure(void): AMateria("cure")
{
	return ;
}

Cure::Cure(const Cure &obj): AMateria("cure")
{
	*this = obj;
	return ;
}

Cure::~Cure(void)
{
	return ;
}

Cure			&Cure::operator=(const Cure &obj)
{
	if (this == &obj)
		return (*this);
	return(*this);
}

AMateria		*Cure::clone(void) const
{
	AMateria	*clone;
	clone = new Cure();
	return (clone);
}

void			Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return ;
}
