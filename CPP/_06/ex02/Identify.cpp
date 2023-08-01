/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:39:12 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/08 10:42:32 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

Identify::Identify(void)
{
	return ;
}

Identify::Identify(Identify const &obj)
{
	*this = obj;
	return ;
}

Identify::~Identify(void)
{
	return ;
}

Identify	&Identify::operator=(Identify const &obj)
{
	if (this == &obj)
		return (*this);
	return (*this);
}

Base		*Identify::generate(void)
{
	int	p;
	Base	*ptr;

	p = rand() % 3;
	if (p == 0)
		ptr = new A();
	else if (p == 1)
		ptr = new B();
	else
		ptr = new C();
	return (ptr);
}

void		Identify::identify(Base *p)
{
	if (dynamic_cast <A *> (p))
		std::cout << "Type: A" << std::endl;
	else if (dynamic_cast <B *> (p))
		std::cout << "Type: B" << std::endl;
	else if (dynamic_cast <C *> (p))
		std::cout << "Type: C" << std::endl;
	return ;
}

void		Identify::identify(Base &p)
{
	try
	{
		(void) dynamic_cast <A&> (p);
		std::cout << "Type A" << std::endl;
	}
	catch (std::exception e)
	{
		try
		{
			(void) dynamic_cast <B&> (p);
			std::cout << "Type: B" << std::endl;
		}
		catch (std::exception e)
		{
			std::cout << "Type: C" << std::endl;
		}
	}
}
