/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:49:50 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/03 12:13:52 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class	Contact
{
	public:

		Contact(void);
		~Contact(void);
		void	set_f_name(std::string f_name);
		void	set_l_name(std::string l_name);
		void	set_n_name(std::string n_name);
		void	set_phone_n(std::string phone_n);
		void	set_darkest_secret(std::string darkest_secret);
		std::string	get_f_name(void) const;
		std::string	get_l_name(void) const;
		std::string	get_n_name(void) const;
		std::string	get_phone_n(void) const;
		std::string	get_darkest_secret(void) const;

	private:

		std::string	_f_name;
		std::string	_l_name;
		std::string	_n_name;
		std::string	_phone_n;
		std::string	_darkest_secret;
};

#endif
