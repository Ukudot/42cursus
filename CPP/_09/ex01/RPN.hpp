/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:26:13 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/15 10:56:36 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# define OPERATORS "+-*/"
# include <iostream>
# include <exception>
# include <string>
# include <stack>

// static class
class	RPN
{
	public:
		// functions
		RPN(void);
		RPN(RPN const &obj);
		~RPN(void);
		RPN			&operator=(RPN const &obj);
		static void		checkValidInput(std::string expr);
		static void		selectOperation(std::stack<int> &stk, char op);
		static void		sum(std::stack<int> &stk);
		static void		sub(std::stack<int> &stk);
		static void		mul(std::stack<int> &stk);
		static void		div(std::stack<int> &stk);

	public:
		// functions
		static void		executeOperation(std::string expr);

	public:
		// classes
		class	BadExpressionException: public std::exception
		{
			virtual const char	*what(void) const throw()
			{
				return ("bad expression");
			}
		};
};

#endif
