/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 08:48:39 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/09 11:34:56 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <exception>
# include <numeric>
# include <algorithm>
# include <stdlib.h>

class	Span
{
	private:
		// variables
		int			_size;
		std::vector<int>	_cont;
		static int		abs_diff(int a, int b);
	public:
		// functions
		Span(int N);
		Span(Span const &obj);
		~Span(void);
		Span			&operator=(Span const &obj);
		int			getSize(void) const;
		std::vector<int>		getCont(void) const;
		void			addNumber(int n);
		int			shortestSpan(void) const;
		int			longestSpan(void) const;
		template <typename InputIterator>
		void			addNumbers(InputIterator begin, InputIterator end);
	public:
		// class
		class	OutOfRangeException: public std::exception
		{
			virtual const char	*what() const throw()
			{
				return ("max size reached, can't add new element");
			}
		};

		class	NotEnoughNumbersException: public std::exception
		{
			virtual const char	*what() const throw()
			{
				return ("span cannot be found with one or zero element");
			}
		};
};

template <typename InputIterator>
void			Span::addNumbers(InputIterator begin, InputIterator end)
{
	while (begin != end)
	{
		this->addNumber(*begin);
		begin++;
	}
}

#endif
