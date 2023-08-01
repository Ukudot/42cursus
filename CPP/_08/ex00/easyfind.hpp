/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 08:48:16 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/09 08:48:19 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <iterator>
# include <exception>
# include <iostream>

class NotFoundException: public std::exception
{
	virtual const char	*what() const throw()
	{
		return ("element not found");
	}
};

template <typename T>
void	easyfind(T container, int n)
{
	if (std::find(container.begin(), container.end(), n) == container.end())
		throw (NotFoundException());
	std::cout << "Element " << n << " found" << std::endl;
}

#endif
