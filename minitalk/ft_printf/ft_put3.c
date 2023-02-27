/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 07:43:52 by gpanico           #+#    #+#             */
/*   Updated: 2023/01/26 08:30:46 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putu(long item)
{
	int	count;

	count = 0;
	ft_putunbr((unsigned int)item, &count);
	return (count);
}

int	ft_putper(long item)
{
	(void) item;
	write(1, "%", 1);
	return (1);
}

int	ft_putp(long item)
{
	int	count;

	count = 2;
	write(1, "0x", 2);
	ft_puthexp((unsigned long) item, &count);
	return (count);
}
