/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:21:26 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/08 10:30:32 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP
# include <iostream>

class	Base
{
	public:
		virtual ~Base(void);
};

class	A: public Base
{
	public:
		A(void);
		virtual ~A(void);
};

class	B: public Base
{
	public:
		B(void);
		virtual ~B(void);
};

class	C: public Base
{
	public:
		C(void);
		virtual ~C(void);
};


#endif
