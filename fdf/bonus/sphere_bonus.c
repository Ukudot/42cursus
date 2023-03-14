/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 07:53:41 by gpanico           #+#    #+#             */
/*   Updated: 2023/03/13 12:19:28 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	ft_x_s(float x_p, float y_p, float r, int dist[2])
{
	float	x_s;

	x_p = x_p - dist[0];
	x_p = x_p / 200;
	y_p = y_p - dist[1];
	y_p = y_p / 200;
	x_s = r * (2 * x_p) / (1 + x_p * x_p + y_p * y_p);
	return (x_s * 200 + dist[0]);
}

float	ft_y_s(float x_p, float y_p, float r, int dist[2])
{
	float	y_s;

	x_p = x_p - dist[0];
	x_p = x_p / 200;
	y_p = y_p - dist[1];
	y_p = y_p / 200;
	y_s = r * (2 * y_p) / (1 + x_p * x_p + y_p * y_p);
	return (y_s * 200 + dist[1]);
}

float	ft_z_s(float x_p, float y_p, float r, int dist[2])
{
	float	z_s;

	x_p = x_p - dist[0];
	x_p = x_p / 200;
	y_p = y_p - dist[1];
	y_p = y_p / 200;
	z_s = r * (-1 + x_p * x_p + y_p * y_p)
		/ (1 + x_p * x_p + y_p * y_p);
	return (z_s * 200);
}

void	ft_mat_to_sphere(t_mat *mat, t_wnd wnd)
{
	int	i;
	int	j;
	int	dist[2];

	mat->sphere_p = ft_create_mat_p(mat->row, mat->col);
	dist[0] = wnd.width / 2;
	dist[1] = wnd.height / 2;
	i = 0;
	while (i < mat->row)
	{
		j = 0;
		while (j < mat->col)
		{
			mat->sphere_p[i][j].x = ft_x_s(mat->mat_p[i][j].x,
					mat->mat_p[i][j].y, -mat->mat_p[i][j].z / 250 + 3, dist);
			mat->sphere_p[i][j].y = ft_y_s(mat->mat_p[i][j].x,
					mat->mat_p[i][j].y, -mat->mat_p[i][j].z / 250 + 3, dist);
			mat->sphere_p[i][j].z = ft_z_s(mat->mat_p[i][j].x,
					mat->mat_p[i][j].y, -mat->mat_p[i][j].z / 250 + 3, dist);
			mat->sphere_p[i][j].color = mat->mat_p[i][j].color;
			j++;
		}
		i++;
	}
}

void	ft_draw_sphere(t_all *all)
{
	int	i;
	int	j;

	mlx_clear_window(all->wnd.x_ptr, all->wnd.wnd_ptr);
	i = 0;
	while (i < all->mat.row)
	{
		j = 0;
		while (j < all->mat.col)
		{
			ft_draw_point(all, all->mat.sphere_p[i][j]);
			j++;
		}
		i++;
	}
	ft_draw_lines_rows(all, &(all->mat), all->mat.sphere_p);
	ft_draw_lines_cols(all, &(all->mat), all->mat.sphere_p);
	mlx_put_image_to_window(all->wnd.x_ptr, all->wnd.wnd_ptr,
		all->img.img_ptr, 0, 0);
	mlx_destroy_image(all->wnd.x_ptr, all->img.img_ptr);
	all->img.img_ptr = mlx_new_image(all->wnd.x_ptr, all->img.width,
			all->img.height);
	all->img.addr = mlx_get_data_addr(all->img.img_ptr,
			&(all->img.bits_per_pixel), &(all->img.size_line),
			&(all->img.endian));
}
