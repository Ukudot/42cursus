/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:09:13 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/09 11:37:46 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include <stdlib.h>

int	main(void)
{
	int	n = 10;
	int	array[n];
	Span	span(n);

	std::cout << "array:";
	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % n;
		std::cout << " " <<array[i];
	}
	std::cout << std::endl;

	span.addNumbers(array, array + n);
	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;
	
	return (0);
}
