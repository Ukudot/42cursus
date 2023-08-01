/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 08:53:10 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/11 09:06:48 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat: public Animal
{
	public:

		Cat(void);
		Cat(const Cat &obj);
		~Cat(void);
		Cat&	operator=(const Cat &obj);
		void	makeSound(void) const;
};

#endif
