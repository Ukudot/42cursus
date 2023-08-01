/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 08:48:36 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/08 09:00:56 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(int data): _data(data)
{
	return ;
}

Data::Data(Data const &obj)
{
	*this = obj;
	return ;
}

Data::~Data(void)
{
	return ;
}

Data	&Data::operator=(Data const &obj)
{
	if (this == &obj)
		return (*this);
	this->_data = obj.getData();
	return (*this);
}

int	Data::getData(void) const
{
	return (this->_data);
}
