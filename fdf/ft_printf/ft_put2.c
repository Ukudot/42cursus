/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 07:42:19 by gpanico           #+#    #+#             */
/*   Updated: 2023/01/26 08:30:32 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putc(long item)
{
	char	c;

	c = (char) item;
	write(1, &c, 1);
	return (1);
}

int	ft_puts(long item)
{
	char	*str;
	size_t	i;
	int		count;

	str = (char *)item;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	count = 0;
	while (str[i])
	{
		count += ft_putc((long) str[i]);
		i++;
	}
	return (count);
}

int	ft_puti(long item)
{
	int	n;
	int	count;

	n = (int) item;
	count = 0;
	if (n < 0)
		count += write(1, "-", 1);
	else
		n *= -1;
	ft_putnbr(n, &count);
	return (count);
}

int	ft_putx(long item)
{
	int	count;

	count = 0;
	ft_puthex((unsigned int)item, &count);
	return (count);
}

int	ft_putxx(long item)
{
	int	count;

	count = 0;
	ft_puthhex((unsigned int)item, &count);
	return (count);
}
