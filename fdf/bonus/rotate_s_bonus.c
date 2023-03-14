/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:45:56 by gpanico           #+#    #+#             */
/*   Updated: 2023/03/13 12:19:11 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_s_rotate_x(t_wnd wnd, t_mat *mat, float theta)
{
	int		i;
	int		j;
	t_point	p;
	float	offset[2];

	offset[0] = wnd.width / 2;
	offset[1] = wnd.height / 2;
	i = 0;
	while (i < mat->row)
	{
		j = 0;
		while (j < mat->col)
		{
			p.x = mat->sphere_p[i][j].x - offset[0];
			p.y = mat->sphere_p[i][j].y - offset[1];
			p.z = mat->sphere_p[i][j].z;
			mat->sphere_p[i][j].x = p.x + offset[0];
			mat->sphere_p[i][j].y = p.y * cos(theta) + p.z * sin(theta)
				+ offset[1];
			mat->sphere_p[i][j].z = -p.y * sin(theta) + p.z * cos(theta);
			j++;
		}
		i++;
	}
}

void	ft_s_rotate_y(t_wnd wnd, t_mat *mat, float theta)
{
	int		i;
	int		j;
	t_point	p;
	float	offset[2];

	offset[0] = wnd.width / 2;
	offset[1] = wnd.height / 2;
	i = 0;
	while (i < mat->row)
	{
		j = 0;
		while (j < mat->col)
		{
			p.x = mat->sphere_p[i][j].x - offset[0];
			p.y = mat->sphere_p[i][j].y - offset[1];
			p.z = mat->sphere_p[i][j].z;
			mat->sphere_p[i][j].x = p.x * cos(theta) - p.z * sin(theta)
				+ offset[0];
			mat->sphere_p[i][j].y = p.y + offset[1];
			mat->sphere_p[i][j].z = p.x * sin(theta) + p.z * cos(theta);
			j++;
		}
		i++;
	}
}

void	ft_s_rotate_z(t_wnd wnd, t_mat *mat, float theta)
{
	int		i;
	int		j;
	t_point	p;
	float	offset[2];

	offset[0] = wnd.width / 2;
	offset[1] = wnd.height / 2;
	i = 0;
	while (i < mat->row)
	{
		j = 0;
		while (j < mat->col)
		{
			p.x = mat->sphere_p[i][j].x - offset[0];
			p.y = mat->sphere_p[i][j].y - offset[1];
			p.z = mat->sphere_p[i][j].z;
			mat->sphere_p[i][j].x = p.x * cos(theta) + p.y * sin(theta)
				+ offset[0];
			mat->sphere_p[i][j].y = -p.x * sin(theta) + p.y * cos(theta)
				+ offset[1];
			mat->sphere_p[i][j].z = p.z;
			j++;
		}
		i++;
	}
}
