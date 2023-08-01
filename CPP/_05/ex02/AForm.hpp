/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:21:48 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/02 11:53:52 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <string>
# include <iostream>
# include <fstream>
# include <ctime>
# include <cstdlib>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	private:
		std::string const	_name;
		bool			_signed;
		int const		_gradeSign;
		int const		_gradeExec;
	public:
		//functions
		AForm(std::string const &name, int const gradeSign, int const gradeExec);
		AForm(AForm const &obj);
		virtual ~AForm(void);
		virtual AForm			&operator=(AForm const &obj);
		std::string const 	getName(void) const;
		bool			getSign(void) const;
		void			setSign(bool value);
		int			getGradeSign(void) const;
		int			getGradeExec(void) const;
		bool			beSigned(Bureaucrat const &b);
		void			checkReq(Bureaucrat const &b) const;
		virtual void		execute(Bureaucrat const &executor) const = 0;
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
		class	NotSignedException: public std::exception
		{
			virtual const char	*what(void) const throw()
			{
				return ("form hasn't been signed yet");
			}
		};
};

std::ostream	&operator<<(std::ostream &os, AForm const &obj);

#endif
