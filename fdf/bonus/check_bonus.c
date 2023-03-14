/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:18:22 by gpanico           #+#    #+#             */
/*   Updated: 2023/03/14 07:37:56 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_check_map(char ***map, t_mat *mat)
{
	int	col;
	int	i;

	i = 0;
	mat->col = ft_count_col(map[i]);
	while (++i < mat->row)
	{
		col = ft_count_col(map[i]);
		if (col != mat->col)
		{
			ft_destroy_map(map, mat->row);
			ft_printf("Map error: line of different size.\n");
			exit(1);
		}
	}
}

int	ft_count_col(char **map_line)
{
	int	col;

	col = 0;
	while (map_line[col])
		col++;
	return (col);
}

void	ft_check_elem(char ***map, t_mat *mat)
{
	int		i;
	int		j;
	char	*comma;

	i = 0;
	while (i < mat->row)
	{
		j = 0;
		while (j < mat->col)
		{
			ft_check_digit(map[i][j], map, mat->row);
			comma = ft_strchr(map[i][j], ',');
			if (comma)
				ft_check_ex(comma + 1, map, mat->row);
			j++;
		}
		i++;
	}
}

void	ft_check_digit(char *elem, char ***map, int row)
{
	int		i;
	long	check;

	i = 0;
	if (elem[i] == '+' || elem[i] == '-')
		i++;
	while (elem[i] && (!i || elem[i] != ','))
	{
		if (!ft_isdigit(elem[i]))
		{
			ft_destroy_map(map, row);
			ft_printf("Map error: invalid sytax\n");
			exit(1);
		}
		i++;
	}
	check = ft_atol(elem);
	if (check < (long) -2147483648 || check > (long) 2147483647)
	{
		ft_destroy_map(map, row);
		ft_printf("Map error: invalid syntax\n");
		exit(1);
	}
}

void	ft_check_ex(char *elem, char ***map, int row)
{
	int	len;

	if (elem[0] == '+')
		elem++;
	len = ft_strlen(elem);
	if (elem[0] != '0' || elem[1] != 'x' || len > 8)
	{
		ft_destroy_map(map, row);
		ft_printf("Map error: invalid syntax\n");
		exit(1);
	}
	while (--len > 1)
	{
		if (!ft_isexa(elem[len]))
		{	
			ft_destroy_map(map, row);
			ft_printf("Map error: invalid syntax\n");
			exit(1);
		}
	}
}
