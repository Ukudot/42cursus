/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:12:58 by gpanico           #+#    #+#             */
/*   Updated: 2023/01/23 08:32:16 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*new;
	size_t		i;

	new = (char *)malloc(count * size);
	if (!new || size > 1 || count > 1)
		return (0);
	i = 0;
	while (i < (count * size))
	{
		new[i] = 0;
		i++;
	}
	return ((void *)new);
}
