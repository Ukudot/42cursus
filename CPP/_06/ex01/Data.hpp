/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 08:45:40 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/08 08:48:26 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class	Data
{
	private:
		int	_data;
	public:
		Data(int data);
		Data(Data const &obj);
		~Data(void);
		Data	&operator=(Data const &obj);
		int	getData(void) const;

};

#endif
