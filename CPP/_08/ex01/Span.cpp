/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 08:51:38 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/09 11:34:40 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(int N): _size(N)
{
	return ;
}

Span::Span(Span const &obj)
{
	*this = obj;
	return ;
}

Span::~Span(void)
{
	return ;
}

Span			&Span::operator=(Span const &obj)
{
	if (this == &obj)
		return (*this);
	this->_size = obj.getSize();
	this->_cont = obj.getCont();
	return (*this);
}

int			Span::getSize(void) const
{
	return (this->_size);
}

std::vector<int>	Span::getCont(void) const
{
	return (this->_cont);
}

void			Span::addNumber(int n)
{
	if (this->_cont.size() < (unsigned long) this->_size)
		this->_cont.push_back(n);
	else
		throw (Span::OutOfRangeException());
}

int			Span::shortestSpan(void) const
{
	std::vector<int>	span;
	std::vector<int>	copy;

	if (this->_cont.size() < 2)
		throw (Span::NotEnoughNumbersException());
	span.resize(this->_cont.size());
	copy = this->_cont;
	std::sort(copy.begin(), copy.end());
	std::adjacent_difference(copy.begin(), copy.end(), span.begin(), Span::abs_diff);
	return (*std::min_element(span.begin()++, span.end()));
}

int			Span::longestSpan(void) const
{
	std::vector<int>	span;
	std::vector<int>	copy;

	if (this->_cont.size() < 2)
		throw (Span::NotEnoughNumbersException());
	span.resize(this->_cont.size());
	copy = this->_cont;
	std::sort(copy.begin(), copy.end());
	return (copy.back() - copy.front());
}

int			Span::abs_diff(int a, int b)
{
	return (std::abs(a - b));
}
