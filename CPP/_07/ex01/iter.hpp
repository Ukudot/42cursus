/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:13:35 by gpanico           #+#    #+#             */
/*   Updated: 2023/06/08 15:27:31 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename U>
void	iter(T *array, int len, void (*f) (U))
{
	for (int i = 0; i < len; i++)
		(*f) (array[i]);
}

#endif
