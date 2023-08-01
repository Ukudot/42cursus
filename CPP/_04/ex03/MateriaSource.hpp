/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 08:28:59 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/01 08:44:22 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <string>
# include <iostream>
# include "Materia.hpp"
# include "Character.hpp"

class	IMateriaSource
{
	public:
		virtual ~IMateriaSource(void);
		virtual void		learnMateria(AMateria *m) = 0;
		virtual AMateria	*createMateria(std::string const &type) = 0;
};

class	MateriaSource: public IMateriaSource
{
	private:
		AMateria	*_inventory[4];
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &obj);
		~MateriaSource(void);
		MateriaSource&	operator=(MateriaSource const &obj);
		AMateria	*getInv(int idx) const;
		void		learnMateria(AMateria *m);
		AMateria	*createMateria(std::string const &type);
};

#endif
