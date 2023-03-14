/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:38:05 by gpanico           #+#    #+#             */
/*   Updated: 2023/03/13 12:14:34 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_draw_point(t_all *all, t_point point)
{
	unsigned int	color;
	int				x;
	int				y;

	x = (point.x - all->wnd.width / 2) * 0.70 + all->wnd.width / 2;
	y = (point.y - all->wnd.height / 2) * 0.70 + all->wnd.height / 2;
	if (x <= 0 || x >= all->wnd.width)
		return ;
	if (y <= 0 || y >= all->wnd.height)
		return ;
	color = mlx_get_color_value(all->wnd.x_ptr, (int) point.color);
	my_mlx_pixel_put(&(all->img), x, y, color);
}

void	ft_draw_lines_rows(t_all *all, t_mat *mat, t_point **points)
{
	int	i;
	int	j;

	i = 0;
	while (i < mat->row)
	{
		j = 1;
		while (j < mat->col)
		{
			ft_draw_line_bresenham(all, points[i][j - 1],
				points[i][j]);
			j++;
		}
		i++;
	}
}

void	ft_draw_lines_cols(t_all *all, t_mat *mat, t_point **points)
{
	int	i;
	int	j;

	i = 1;
	while (i < mat->row)
	{
		j = 0;
		while (j < mat->col)
		{
			ft_draw_line_bresenham(all, points[i - 1][j],
				points[i][j]);
			j++;
		}
		i++;
	}
}

void	ft_draw_line(t_all *all, t_point point1, t_point point2)
{
	float	i;
	float	d[2];
	float	length;
	float	alpha;
	t_point	n_p;

	d[0] = point2.x - point1.x;
	d[1] = point2.y - point1.y;
	length = sqrt(d[0] * d[0] + d[1] * d[1]);
	alpha = atan(d[1] / d[0]);
	if (d[0] < 0)
		alpha += M_PI;
	i = 0;
	while (i < length)
	{
		n_p.x = point1.x + i * cos(alpha);
		n_p.y = point1.y + i * sin(alpha);
		if (point1.color != point2.color)
			n_p.color = ft_color_line(point1.color, point2.color, i, length);
		else
			n_p.color = point1.color;
		ft_draw_point(all, n_p);
		i++;
	}
}

void	ft_draw_mat_p(t_all *all)
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
			ft_draw_point(all, all->mat.mat_p[i][j]);
			j++;
		}
		i++;
	}
	ft_draw_lines_rows(all, &(all->mat), all->mat.mat_p);
	ft_draw_lines_cols(all, &(all->mat), all->mat.mat_p);
	mlx_put_image_to_window(all->wnd.x_ptr, all->wnd.wnd_ptr,
		all->img.img_ptr, 0, 0);
	mlx_destroy_image(all->wnd.x_ptr, all->img.img_ptr);
	all->img.img_ptr = mlx_new_image(all->wnd.x_ptr, all->img.width,
			all->img.height);
	all->img.addr = mlx_get_data_addr(all->img.img_ptr,
			&(all->img.bits_per_pixel), &(all->img.size_line),
			&(all->img.endian));
}
