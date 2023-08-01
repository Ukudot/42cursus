/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:01:06 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/08 09:10:58 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data		prova(13);
	uintptr_t	raw;

	std::cout << "Data address: " << &prova << std::endl;
	std::cout << "Data content: " << prova.getData() << std::endl;

	raw = Serializer::serialize(&prova);
	std::cout << "Serialized: " << raw << std::endl;
	
	
	std::cout << "Data address: " << Serializer::deserialize(raw) << std::endl;
	std::cout << "Data content: " << Serializer::deserialize(raw)->getData() << std::endl;
	return (0);
}
