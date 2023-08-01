/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:53:37 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/03 12:13:33 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "main.hpp"

Contact::Contact(void)
{
	this->_f_name = "";
	this->_l_name = "";
	this->_n_name = "";
	this->_phone_n = "";
	this->_darkest_secret = "";
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::set_f_name(std::string f_name)
{
	this->_f_name = f_name;
	return ;
}

void	Contact::set_l_name(std::string l_name)
{
	this->_l_name = l_name;
	return ;
}

void	Contact::set_n_name(std::string n_name)
{
	this->_n_name = n_name;
	return ;
}

void	Contact::set_phone_n(std::string phone_n)
{
	this->_phone_n = phone_n;
	return ;
}

void	Contact::set_darkest_secret(std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
	return ;
}

std::string	Contact::get_f_name(void) const
{
	return (this->_f_name);
}

std::string	Contact::get_l_name(void) const
{
	return (this->_l_name);
}

std::string	Contact::get_n_name(void) const
{
	return (this->_n_name);
}

std::string	Contact::get_phone_n(void) const
{
	return (this->_phone_n);
}

std::string	Contact::get_darkest_secret(void) const
{
	return (this->_darkest_secret);
}
