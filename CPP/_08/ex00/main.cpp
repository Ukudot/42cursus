/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 08:48:24 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/09 08:57:24 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"

int main(void)
{
	std::cout << "vector" << std::endl;
	std::vector<int>	vect;

	for (int i = 0; i < 5; i++)
		vect.push_back(i);
	try
	{
		easyfind(vect, 3);
		easyfind(vect, 7);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "deck" << std::endl;
	std::deque<int>	deck(vect.begin(), vect.end());

	try
	{
		easyfind(deck, 3);
		easyfind(deck, 7);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "list" << std::endl;
	std::list<int>	list(vect.begin(), vect.end());

	try
	{
		easyfind(list, 3);
		easyfind(list, 7);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
