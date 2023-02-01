/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:57:47 by gpanico           #+#    #+#             */
/*   Updated: 2023/01/26 08:34:46 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_fpointer(int (*putitems[9])(long item))
{
	putitems[0] = &ft_putc;
	putitems[1] = &ft_puts;
	putitems[2] = &ft_putp;
	putitems[3] = &ft_puti;
	putitems[4] = &ft_puti;
	putitems[5] = &ft_putu;
	putitems[6] = &ft_putx;
	putitems[7] = &ft_putxx;
	putitems[8] = &ft_putper;
}

int	ft_insert_identifier(const char *str, long item)
{
	int		count;
	size_t	index;
	int		(*putitems[9])(long item);

	index = ft_strchr(IDENTIFIERS, *str) - IDENTIFIERS;
	ft_init_fpointer(putitems);
	count = (*putitems[index])(item);
	return (count);
}

int	ft_is_identifier(const char *str, size_t *i)
{
	if (str[0] == '%')
	{
		*i = *i + 1;
		if (ft_strchr(IDENTIFIERS, str[1]))
			return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	size_t	i;
	long	item;
	int		count;

	i = 0;
	count = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (ft_is_identifier(&str[i], &i))
		{
			if (str[i] != '%')
				item = va_arg(ptr, long);
			count += ft_insert_identifier(&str[i], item);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(ptr);
	return (count);
}
