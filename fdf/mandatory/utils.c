/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:19:00 by gpanico           #+#    #+#             */
/*   Updated: 2023/03/13 14:28:49 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	*ft_realloc(void *p, size_t size, int dim, int new_dim)
{
	char		*new_p;
	size_t		i;

	new_p = (char *)malloc(size * new_dim);
	i = 0;
	while (i < size * new_dim)
	{
		if (i < size * dim)
			new_p[i] = ((char *) p)[i];
		else
			new_p[i] = 0;
		i++;
	}
	free(p);
	return ((void *) new_p);
}

unsigned long	ft_atoul(char *num)
{
	unsigned long	n;
	int				i;

	n = 0;
	i = 0;
	while (num[i] == ' ')
		i++;
	while (ft_isexa(num[i]))
	{
		num[i] = ft_toupper(num[i]);
		n *= 16;
		if (ft_isdigit(num[i]))
			n += (num[i] - 48);
		else
			n += (num[i] - 55);
		i++;
	}
	return (n);
}

long	ft_atol(char *num)
{
	long	n;
	int		i;

	i = 0;
	n = 1;
	if (num[i] == '+' || num [i] == '-')
	{
		if (num[i] == '-')
			n = -1;
		i++;
	}
	n *= (long) ft_atoul(&num[i]);
	return (n);
}

int	ft_isexa(char c)
{
	c = ft_toupper(c);
	if (ft_isdigit(c) || (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}

void	ft_swap(long *a, long *b)
{
	long	c;

	c = *a;
	*a = *b;
	*b = c;
}
