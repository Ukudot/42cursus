/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 07:44:03 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/03 10:00:25 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	std::string	line;

	if (argc == 1)
		std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE \a*" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			line = argv[i];
			for (int j = 0; line[j]; j++)
				line[j] = toupper(argv[i][j]);
			std::cout << line;
		}
		std::cout << std::endl;
	}
	return (0);
}
