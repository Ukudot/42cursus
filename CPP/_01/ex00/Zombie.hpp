/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:13:21 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/05 15:33:26 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class Zombie
{
	public:

		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);

	private:

		std::string	name;
};

// functions
Zombie	*newZombie(std::string name);
void	randomChump(std::string name);


#endif
