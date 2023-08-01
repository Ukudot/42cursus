/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:27:25 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/11 09:35:31 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>
# include <iostream>

class WrongAnimal
{
	public:

		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &obj);
		~WrongAnimal(void);
		WrongAnimal&		operator=(const WrongAnimal &obj);
		void		setType(std::string type);
		std::string	getType(void) const;
		void		makeSound(void) const;

	protected:

		std::string	_type;
};

#endif
