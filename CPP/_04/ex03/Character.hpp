/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:01:10 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/01 08:52:41 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <string>
# include <iostream>
# include "Materia.hpp"

class	ICharacter
{
	public:
		virtual ~ICharacter(void);
		virtual std::string const	&getName(void) const = 0;
		virtual void			equip(AMateria* m) = 0;
		virtual void			unequip(int idx) = 0;
		virtual void			use(int idx, ICharacter &target) = 0;
};

class	Character: public ICharacter
{
	private:
		AMateria	*_inventory[4];
		AMateria	*_unequiped[200];
		std::string	_name;
	public:
		Character(std::string const &name);
		Character(const Character &obj);
		~Character(void);
		Character&	operator=(const Character &obj);
		AMateria	*getInv(int idx) const;
		AMateria	*getUne(int idx) const;
		std::string const	&getName(void) const;
		void			equip(AMateria* m);
		void			unequip(int idx);
		void			use(int idx, ICharacter &target);
};

#endif
