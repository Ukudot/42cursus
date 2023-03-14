/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:06:38 by gpanico           #+#    #+#             */
/*   Updated: 2023/03/13 11:58:34 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_rotate_x(t_mat *mat, float theta)
{
	int		i;
	int		j;
	t_point	p;
	float	offset[2];

	offset[0] = mat->mat_p[mat->row / 2][mat->col / 2].x;
	offset[1] = mat->mat_p[mat->row / 2][mat->col / 2].y;
	i = 0;
	while (i < mat->row)
	{
		j = 0;
		while (j < mat->col)
		{
			p.x = mat->mat_p[i][j].x - offset[0];
			p.y = mat->mat_p[i][j].y - offset[1];
			p.z = mat->mat_p[i][j].z;
			mat->mat_p[i][j].x = p.x + offset[0];
			mat->mat_p[i][j].y = p.y * cos(theta) + p.z * sin(theta)
				+ offset[1];
			mat->mat_p[i][j].z = -p.y * sin(theta) + p.z * cos(theta);
			j++;
		}
		i++;
	}
}

void	ft_rotate_y(t_mat *mat, float theta)
{
	int		i;
	int		j;
	t_point	p;
	float	offset[2];

	offset[0] = mat->mat_p[mat->row / 2][mat->col / 2].x;
	offset[1] = mat->mat_p[mat->row / 2][mat->col / 2].y;
	i = 0;
	while (i < mat->row)
	{
		j = 0;
		while (j < mat->col)
		{
			p.x = mat->mat_p[i][j].x - offset[0];
			p.y = mat->mat_p[i][j].y - offset[1];
			p.z = mat->mat_p[i][j].z;
			mat->mat_p[i][j].x = p.x * cos(theta) - p.z * sin(theta)
				+ offset[0];
			mat->mat_p[i][j].y = p.y + offset[1];
			mat->mat_p[i][j].z = p.x * sin(theta) + p.z * cos(theta);
			j++;
		}
		i++;
	}
}

void	ft_rotate_z(t_mat *mat, float theta)
{
	int		i;
	int		j;
	t_point	p;
	float	offset[2];

	offset[0] = mat->mat_p[mat->row / 2][mat->col / 2].x;
	offset[1] = mat->mat_p[mat->row / 2][mat->col / 2].y;
	i = 0;
	while (i < mat->row)
	{
		j = 0;
		while (j < mat->col)
		{
			p.x = mat->mat_p[i][j].x - offset[0];
			p.y = mat->mat_p[i][j].y - offset[1];
			p.z = mat->mat_p[i][j].z;
			mat->mat_p[i][j].x = p.x * cos(theta) + p.y * sin(theta)
				+ offset[0];
			mat->mat_p[i][j].y = -p.x * sin(theta) + p.y * cos(theta)
				+ offset[1];
			mat->mat_p[i][j].z = p.z;
			j++;
		}
		i++;
	}
}

void	ft_rotate_inverse_x(t_mat *mat, float theta)
{
	int		i;
	int		j;
	t_point	p;
	float	offset[2];

	offset[0] = mat->mat_p[mat->row / 2][mat->col / 2].x;
	offset[1] = mat->mat_p[mat->row / 2][mat->col / 2].y;
	i = 0;
	while (i < mat->row)
	{
		j = 0;
		while (j < mat->col)
		{
			p.x = mat->mat_p[i][j].x - offset[0];
			p.y = mat->mat_p[i][j].y - offset[1];
			p.z = mat->mat_p[i][j].z;
			mat->mat_p[i][j].x = p.x + offset[0];
			mat->mat_p[i][j].y = p.y * cos(theta) - p.z * sin(theta)
				+ offset[1];
			mat->mat_p[i][j].z = p.y * sin(theta) + p.z * cos(theta);
			j++;
		}
		i++;
	}
}

void	ft_rotate_inverse_y(t_mat *mat, float theta)
{
	int		i;
	int		j;
	t_point	p;
	float	offset[2];

	offset[0] = mat->mat_p[mat->row / 2][mat->col / 2].x;
	offset[1] = mat->mat_p[mat->row / 2][mat->col / 2].y;
	i = 0;
	while (i < mat->row)
	{
		j = 0;
		while (j < mat->col)
		{
			p.x = mat->mat_p[i][j].x - offset[0];
			p.y = mat->mat_p[i][j].y - offset[1];
			p.z = mat->mat_p[i][j].z;
			mat->mat_p[i][j].x = p.x * cos(theta) + p.z * sin(theta)
				+ offset[0];
			mat->mat_p[i][j].y = p.y + offset[1];
			mat->mat_p[i][j].z = -p.x * sin(theta) + p.z * cos(theta);
			j++;
		}
		i++;
	}
}
