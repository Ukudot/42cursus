/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:57:38 by gpanico           #+#    #+#             */
/*   Updated: 2023/05/11 11:43:35 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>
# include <iostream>

class Brain
{
	public:

		Brain(void);
		Brain(const Brain &obj);
		~Brain(void);
		Brain&		operator=(const Brain& obj);
		std::string	getIdea(int i) const;
		void		setIdea(std::string idea, int i);

	private:

		std::string	_ideas[100];
};

#endif
