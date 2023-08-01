/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:21:48 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/02 08:56:32 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	private:
		std::string const	_name;
		bool			_signed;
		int const		_gradeSign;
		int const		_gradeExec;
	public:
		//functions
		Form(std::string const &name, int const gradeSign, int const gradeExec);
		Form(Form const &obj);
		~Form(void);
		Form			&operator=(Form const &obj);
		std::string const 	getName(void) const;
		bool			getSign(void) const;
		int			getGradeSign(void) const;
		int			getGradeExec(void) const;
		bool			beSigned(Bureaucrat const &b);
	public:
		//class
		class	GradeTooHighException: public std::exception
		{
			virtual const char	*what(void) const throw()
			{
				return ("grade is too high");
			}
		};
		class	GradeTooLowException: public std::exception
		{
			virtual const char	*what(void) const throw()
			{
				return ("grade is too low");
			}
		};
};

std::ostream	&operator<<(std::ostream &os, Form const &obj);

#endif

