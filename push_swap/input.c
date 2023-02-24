/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:24:41 by gpanico           #+#    #+#             */
/*   Updated: 2023/02/23 12:14:59 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 2));
	str[len1 + len2 + 1] = 0;
	while (--len2 >= 0)
		str[len1 + len2 + 1] = s2[len2];
	str[len1] = 32;
	while (--len1 >= 0)
		str[len1] = s1[len1];
	if (s1 != NULL)
		free(s1);
	return (str);
}

int	ft_isspace(int n)
{
	if ((n <= 13 && n >= 9) || n == 32)
		return (1);
	return (0);
}

long	ft_atoi(char *num)
{
	int		i;
	long	n;
	int		sign;

	i = 0;
	n = 0;
	sign = 0;
	while (ft_isspace(num[i]))
		i++;
	if (num[i] == '+' || num[i] == '-')
	{
		if (num[i] == '-')
			sign = 1;
		i++;
	}
	while (num[i] <= '9' && num[i] >= '0')
	{
		n *= 10;
		n -= (num[i] - 48);
		i++;
	}
	if (sign)
		return (n);
	return (-1 * n);
}

char	*ft_parse_input(int argc, char **argv)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	while (++i < argc)
		str = ft_strjoin(str, argv[i]);
	if (ft_check_digit(str))
	{
		free(str);
		write(2, "Error\n", 6);
		exit(1);
	}
	return (str);
}
