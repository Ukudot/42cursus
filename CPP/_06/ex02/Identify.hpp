/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:34:59 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/08 10:35:03 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP
# include <stdlib.h>
# include <exception>
# include "time.h"
# include "Base.hpp"

class	Identify
{
	private:
		Identify(void);
		Identify(Identify const &obj);
		~Identify(void);
		Identify	&operator=(Identify const &obj);
	public:
		static Base	*generate(void);
		static void	identify(Base *p);
		static void	identify(Base &p);
};

#endif
