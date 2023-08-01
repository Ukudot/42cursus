/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 08:27:23 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/11 13:34:33 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>
# include "Brain.hpp"

class Animal
{
	public:

		Animal(void);
		Animal(const Animal &obj);
		virtual	~Animal(void);
		Animal&				operator=(const Animal &obj);
		void				setType(std::string type);
		std::string			getType(void) const;
		virtual void		makeSound(void) const;
		virtual Brain&		getBrain(void) const = 0;

	protected:

		std::string	_type;
};

#endif
