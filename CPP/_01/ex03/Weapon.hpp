/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:52:06 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/18 08:18:23 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>
# include <iostream>

class Weapon
{
	public:
	
		Weapon(std::string type);
		~Weapon(void);
		const std::string&		getType(void) const;
		void				setType(std::string type);

	private:

		std::string			_type;
};

#endif
