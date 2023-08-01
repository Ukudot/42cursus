/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:24:42 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/08 10:40:11 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

int	main(void)
{
	Base	*p;

	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		p = Identify::generate();
		Identify::identify(p);
		Identify::identify(*p);
		delete p;
	}
	return (0);
}
