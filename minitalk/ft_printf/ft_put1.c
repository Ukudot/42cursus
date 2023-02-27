/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 07:40:29 by gpanico           #+#    #+#             */
/*   Updated: 2023/01/26 08:30:22 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	if (n / 10 == 0)
	{
		*count = *count + write(1, &"0123456789"[-n], 1);
		return ;
	}
	ft_putnbr(n / 10, count);
	*count = *count + write(1, &"0123456789"[-(n % 10)], 1);
}

void	ft_puthex(unsigned int n, int *count)
{
	if (n / 16 == 0)
	{
		*count = *count + write(1, &"0123456789abcdef"[n], 1);
		return ;
	}
	ft_puthex(n / 16, count);
	*count = *count + write(1, &"0123456789abcdef"[n % 16], 1);
}

void	ft_puthexp(unsigned long n, int *count)
{
	if (n / 16 == 0)
	{
		*count = *count + write(1, &"0123456789abcdef"[n], 1);
		return ;
	}
	ft_puthexp(n / 16, count);
	*count = *count + write(1, &"0123456789abcdef"[n % 16], 1);
}

void	ft_puthhex(unsigned int n, int *count)
{
	if (n / 16 == 0)
	{
		*count = *count + write(1, &"0123456789ABCDEF"[n], 1);
		return ;
	}
	ft_puthhex(n / 16, count);
	*count = *count + write(1, &"0123456789ABCDEF"[n % 16], 1);
}

void	ft_putunbr(unsigned int n, int *count)
{
	if (n / 10 == 0)
	{
		*count = *count + write(1, &"0123456789"[n], 1);
		return ;
	}
	ft_putunbr(n / 10, count);
	*count = *count + write(1, &"0123456789"[n % 10], 1);
}
