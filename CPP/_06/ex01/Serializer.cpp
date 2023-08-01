/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 08:29:22 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/08 09:11:14 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	return ;
}

Serializer::Serializer(Serializer const &obj)
{
	*this = obj;
	return ;
}

Serializer::~Serializer(void)
{
	return ;
}

Serializer	&Serializer::operator=(Serializer const &obj)
{
	if (this == &obj)
		return (*this);
	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t	raw;

	raw = reinterpret_cast <uintptr_t> (ptr);
	return (raw);
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	Data	*ptr;

	ptr = reinterpret_cast <Data *> (raw);
	return (ptr);
}
