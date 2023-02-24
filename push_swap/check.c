/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:15:16 by gpanico           #+#    #+#             */
/*   Updated: 2023/02/23 12:14:29 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_digit(char n)
{
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}

int	ft_check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_digit(str[i]))
			i++;
		else if (i && (str[i] == '+' || str[i] == '-')
			&& !ft_is_digit(str[i - 1]))
		{
			if ((str[i] == '+' || str[i] == '-') && ft_is_digit(str[i + 1]))
				i++;
			else
				return (1);
		}
		else if (ft_isspace(str[i]))
			i++;
		else
			return (1);
	}
	return (0);
}
