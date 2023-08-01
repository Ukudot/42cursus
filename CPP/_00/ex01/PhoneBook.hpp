/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:30:07 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/03 12:41:02 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class	PhoneBook
{
	public:

		PhoneBook(void);
		~PhoneBook(void);
		// functions
		void	add_cont(void);
		void	print_padded(std::string line) const;
		void	display_cont(void) const;
		void	display_user(int id) const;
		void	search_cont(void) const;

	private:

		// variables
		Contact	_conts[8];
		int		_n_cont;
};

#endif
