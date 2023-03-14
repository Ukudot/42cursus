/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:18:40 by gpanico           #+#    #+#             */
/*   Updated: 2023/03/13 12:16:10 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_map_to_mat(char ***map, t_mat *mat, t_wnd wnd)
{
	int	i;
	int	j;
	int	x_dist;
	int	y_dist;

	mat->mat_p = ft_create_mat_p(mat->row, mat->col);
	i = 0;
	x_dist = wnd.width / mat->col;
	y_dist = wnd.height / mat->row;
	while (i < mat->row)
	{
		j = 0;
		while (j < mat->col)
		{
			mat->mat_p[i][j].x = j * x_dist + x_dist / 2;
			mat->mat_p[i][j].y = i * y_dist + y_dist / 2;
			mat->mat_p[i][j].z = -ft_atoi(map[i][j]);
			mat->mat_p[i][j].color = ft_color(map[i][j]);
			j++;
		}
		i++;
	}
	ft_destroy_map(map, mat->row);
}

unsigned long	ft_color(char *elem)
{
	char	*x;

	x = ft_strchr(elem, 'x');
	if (x)
		return (ft_atoul(x + 1));
	return (0x00ffffff);
}

t_point	**ft_create_mat_p(int row, int col)
{
	t_point	**mat_p;
	int		i;

	mat_p = (t_point **)malloc(sizeof(t_point *) * row);
	i = 0;
	while (i < row)
	{
		mat_p[i] = (t_point *)malloc(sizeof(t_point) * col);
		i++;
	}
	return (mat_p);
}

void	ft_destroy_mat_p(t_point **mat_p, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(mat_p[i]);
		i++;
	}
	free(mat_p);
}

void	ft_normalize(t_mat *mat, t_wnd wnd)
{
	int		i;
	int		j;
	double	z;

	i = -1;
	z = 0;
	while (++i < mat->row)
	{
		j = -1;
		while (++j < mat->col)
			z = fmax(z, fabs(mat->mat_p[i][j].z));
	}
	if (z == 0)
		return ;
	i = -1;
	while (++i < mat->row)
	{
		j = -1;
		while (++j < mat->col)
			mat->mat_p[i][j].z = mat->mat_p[i][j].z / z * wnd.height / 4;
	}
}
