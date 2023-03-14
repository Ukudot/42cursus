/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:25:11 by gpanico           #+#    #+#             */
/*   Updated: 2023/03/13 11:55:37 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	ft_new_point_low(int x, int p1[2], int p2[2], long color[2])
{
	t_point	n_p;

	n_p.color = ft_color_line(color[0], color[1], x - p1[0], p2[0] - p1[0]);
	n_p.x = x;
	n_p.y = p1[1];
	return (n_p);
}

t_point	ft_new_point_high(int y, int p1[2], int p2[2], long color[2])
{
	t_point	n_p;

	n_p.color = ft_color_line(color[0], color[1], y - p1[1], p2[1] - p1[1]);
	n_p.x = p1[0];
	n_p.y = y;
	return (n_p);
}

void	ft_bresenham_high(t_all *all, int p1[2], int p2[2], long color[2])
{
	int		d[3];
	int		x_i;
	int		y;

	d[0] = p2[0] - p1[0];
	d[1] = p2[1] - p1[1];
	x_i = 1;
	if (d[0] < 0)
	{
		x_i = -1;
		d[0] = -d[0];
	}
	d[2] = (2 * d[0]) - d[1];
	y = p1[1] - 1;
	while (++y <= p2[1])
	{
		ft_draw_point(all, ft_new_point_high(y, p1, p2, color));
		if (d[2] > 0)
		{
			p1[0] = p1[0] + x_i;
			d[2] = d[2] - 2 * d[1];
		}
		d[2] = d[2] + 2 * d[0];
	}
}

void	ft_bresenham_low(t_all *all, int p1[2], int p2[2], long color[2])
{
	int		d[3];
	int		y_i;
	int		x;

	d[0] = p2[0] - p1[0];
	d[1] = p2[1] - p1[1];
	y_i = 1;
	if (d[1] < 0)
	{
		y_i = -1;
		d[1] = -d[1];
	}
	d[2] = (2 * d[1]) - d[0];
	x = p1[0] - 1;
	while (++x <= p2[0])
	{
		ft_draw_point(all, ft_new_point_low(x, p1, p2, color));
		if (d[2] > 0)
		{
			p1[1] = p1[1] + y_i;
			d[2] = d[2] - 2 * d[0];
		}
		d[2] = d[2] + 2 * d[1];
	}
}

void	ft_draw_line_bresenham(t_all *all, t_point p_1, t_point p_2)
{
	int		p1[2];
	int		p2[2];
	long	color[2];

	p1[0] = p_1.x;
	p1[1] = p_1.y;
	p2[0] = p_2.x;
	p2[1] = p_2.y;
	color[0] = p_1.color;
	color[1] = p_2.color;
	if (abs(p1[1] - p2[1]) < abs(p1[0] - p2[0]))
		ft_line_bresenham(all, p1, p2, color);
	else
		ft_line_r_bresenham(all, p1, p2, color);
}
