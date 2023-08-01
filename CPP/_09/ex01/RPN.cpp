/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:35:26 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/15 10:58:38 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
	return ;
}

RPN::RPN(RPN const &obj)
{
	*this = obj;
	return ;
}

RPN::~RPN(void)
{
	return ;
}

RPN	&RPN::operator=(RPN const &obj)
{
	if (this == &obj)
		return (*this);
	return (*this);
}

void	RPN::executeOperation(std::string expr)
{
	std::stack<int>	stk;
	int		len;

	RPN::checkValidInput(expr);
	len = expr.length();
	for (int i = 0; i < len; i++)
	{
		if (isdigit(expr[i]))
			stk.push(static_cast<int>(expr[i] - 48));
		else if (expr[i] == ' ')
			continue;
		else
			RPN::selectOperation(stk, expr[i]);
	}
	if (stk.size() != 1)
		throw (RPN::BadExpressionException());
	std::cout << stk.top() << std::endl;
}

void	RPN::checkValidInput(std::string expr)
{
	std::string	operators;
	int		len;

	len = expr.length();
	operators = OPERATORS;
	for (int i = 0; i < len; i++)
	{
		if (i % 2 == 0)
		{
			if (!isdigit(expr[i]) && operators.find(expr[i]) == std::string::npos)
				throw (RPN::BadExpressionException());
		}
		else
			if (expr[i] != ' ')
				throw (RPN::BadExpressionException());
	}
}

void	RPN::selectOperation(std::stack<int> &stk, char op)
{
	if (stk.size() <= 1)
		throw (RPN::BadExpressionException());
	switch (op)
	{
		case 42:
			mul(stk);
			break ;
		case 43:
			sum(stk);
			break ;
		case 45:
			sub(stk);
			break ;
		case 47:
			div(stk);
			break ;
	}
}

void	RPN::sum(std::stack<int> &stk)
{
	int	a;
	int	b;
	
	b = stk.top();
	stk.pop();
	a = stk.top();
	stk.pop();
	stk.push(a + b);
}

void	RPN::sub(std::stack<int> &stk)
{
	int	a;
	int	b;
	
	b = stk.top();
	stk.pop();
	a = stk.top();
	stk.pop();
	stk.push(a - b);
}

void	RPN::mul(std::stack<int> &stk)
{
	int	a;
	int	b;
	
	b = stk.top();
	stk.pop();
	a = stk.top();
	stk.pop();
	stk.push(a * b);
}

void	RPN::div(std::stack<int> &stk)
{
	int	a;
	int	b;
	
	b = stk.top();
	stk.pop();
	a = stk.top();
	stk.pop();
	stk.push(a / b);
}
