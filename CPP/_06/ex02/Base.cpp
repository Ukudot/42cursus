/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:24:02 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/08 09:33:47 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(void)
{
	std::cout << "Base destructor called" << std::endl;
	return ;
}

A::A(void)
{
	std::cout << "A constructor called" << std::endl;
}

A::~A(void)
{
	std::cout << "A desctructor called" << std::endl;
}

B::B(void)
{
	std::cout << "B constructor called" << std::endl;
}

B::~B(void)
{
	std::cout << "B desctructor called" << std::endl;
}

C::C(void)
{
	std::cout << "C constructor called" << std::endl;
}

C::~C(void)
{
	std::cout << "C desctructor called" << std::endl;
}
