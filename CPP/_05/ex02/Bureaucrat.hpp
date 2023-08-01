/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:27:56 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/02 09:53:12 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>
# include "AForm.hpp"

class	AForm;

class	Bureaucrat
{
	private:
		std::string	_name;
		int		_grade;
	public:
		//function
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &obj);
		~Bureaucrat(void);
		Bureaucrat	&operator=(Bureaucrat const &obj);
		std::string	getName(void) const;
		int		getGrade(void) const;
		void		incr(void);
		void		decr(void);
		void		signForm(AForm &f);
		void		executeForm(AForm const &form);
	public:
		//class
		class	GradeTooHighException: public std::exception
		{
			virtual const char	*what() const throw()
			{
				return ("Invalid bureaucrat operation: grade is greater than 1");
			}
		};
		class	GradeTooLowException: public std::exception
		{
			virtual const char	*what() const throw()
			{
				return ("Invalid bureaucrat operation: grade is less than 150");
			}
		};
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
