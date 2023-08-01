/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 08:38:38 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/11 11:58:41 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	public:

		Dog(void);
		Dog(const Dog &obj);
		~Dog(void);
		Dog&	operator=(const Dog &obj);
		void	makeSound(void) const;
		Brain&	getBrain(void) const;

	private:

		Brain	*_brain;
};

#endif
