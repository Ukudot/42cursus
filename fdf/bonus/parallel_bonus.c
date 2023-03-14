/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:41:41 by gpanico           #+#    #+#             */
/*   Updated: 2023/03/13 12:16:27 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_copy_mat(t_point **dest, t_point **src, int row, int col)
{
	int	i;
	int	j;

	i = -1;
	while (++i < row)
	{
		j = -1;
		while (++j < col)
		{
			dest[i][j].x = src[i][j].x;
			dest[i][j].y = src[i][j].y;
			dest[i][j].z = src[i][j].z;
			dest[i][j].color = src[i][j].color;
		}
	}
}

void	ft_mat_to_parallel(t_mat *mat)
{
	mat->p_top_p = ft_create_mat_p(mat->row, mat->col);
	mat->p_front_p = ft_create_mat_p(mat->row, mat->col);
	mat->p_side_p = ft_create_mat_p(mat->row, mat->col);
	ft_copy_mat(mat->p_top_p, mat->mat_p, mat->row, mat->col);
	ft_copy_mat(mat->p_front_p, mat->mat_p, mat->row, mat->col);
	ft_copy_mat(mat->p_side_p, mat->mat_p, mat->row, mat->col);
	ft_front_rotate_x(mat, M_PI / 2);
	ft_side_rotate_x(mat, M_PI / 2);
	ft_side_rotate_y(mat, -M_PI / 2);
}
