/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:14:08 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/02 12:53:42 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"

class	Intern
{
	public:
		//funcitons
		Intern(void);
		Intern(Intern const &obj);
		~Intern(void);
		Intern	&operator=(Intern const &obj);
		void	checkForm(std::string name) const;
		AForm	*makeForm(std::string name, std::string target);
	public:
		//class
		class	RequestNotExistException: public std::exception
		{
			virtual const char	*what() const throw()
			{
				return ("try the next office for this type of form");
			}
		};
};

#endif
