/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:24:41 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/12 10:26:23 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>
# include <deque>
# include <iostream>

template <typename T, typename container_type = std::deque<T> >
class	MutantStack: public std::stack<T, container_type>
{
	public:
		MutantStack(void): MutantStack<T, container_type>::stack()
		{
			return ;
		};
		MutantStack(MutantStack<T, container_type> const &obj): MutantStack<T, container_type>::stack(obj)
		{
			*this = obj;
		};
		~MutantStack(void)
		{
			return ;	
		};
		MutantStack					&operator=(MutantStack<T, container_type> const &obj)
		{
			if (this == &obj)
				return (*this);
			this->c = obj.c;
			return (*this);
		};
		typedef typename container_type::iterator	iterator;
		iterator					begin()
		{
			return (this->c.begin());
		};
		iterator					end()
		{
			return (this->c.end());
		};	
};

#endif
