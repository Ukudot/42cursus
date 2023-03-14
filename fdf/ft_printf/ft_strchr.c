/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:26:56 by gpanico           #+#    #+#             */
/*   Updated: 2023/01/26 08:30:58 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char) c == (unsigned char)s[i])
			return ((char *) &s[i]);
		i++;
	}
	if ((unsigned char) c == 0)
		return ((char *) &s[i]);
	return (0);
}
