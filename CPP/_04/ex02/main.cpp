/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 08:56:09 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/11 13:37:36 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int	main(void)
{
	Animal *animals[50];
	for (int i = 0; i < 50; i++)
	{
		if (i < 25)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	(animals[0]->getBrain()).setIdea("ciao", 0);
	std::cout << "First cat first idea: " << (animals[0]->getBrain()).getIdea(0) << std::endl;
	for (int i = 1; i < 50; i++)
		std::cout << i << " animal first idea: " << (animals[i]->getBrain()).getIdea(0) << std::endl;
	for (int i = 0; i < 50; i++)
		delete animals[i];
	return (0);
}
