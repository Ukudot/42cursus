/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:54:46 by gpanico           #+#    #+#             */
/*   Updated: 2023/03/13 12:14:23 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_draw_p_top_p(t_all *all)
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
			ft_draw_point(all, all->mat.p_top_p[i][j]);
			j++;
		}
		i++;
	}
	ft_draw_lines_rows(all, &(all->mat), all->mat.p_top_p);
	ft_draw_lines_cols(all, &(all->mat), all->mat.p_top_p);
	mlx_put_image_to_window(all->wnd.x_ptr, all->wnd.wnd_ptr,
		all->img.img_ptr, 0, 0);
	mlx_destroy_image(all->wnd.x_ptr, all->img.img_ptr);
	all->img.img_ptr = mlx_new_image(all->wnd.x_ptr, all->img.width,
			all->img.height);
	all->img.addr = mlx_get_data_addr(all->img.img_ptr,
			&(all->img.bits_per_pixel), &(all->img.size_line),
			&(all->img.endian));
}

void	ft_draw_p_front_p(t_all *all)
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
			ft_draw_point(all, all->mat.p_front_p[i][j]);
			j++;
		}
		i++;
	}
	ft_draw_lines_rows(all, &(all->mat), all->mat.p_front_p);
	ft_draw_lines_cols(all, &(all->mat), all->mat.p_front_p);
	mlx_put_image_to_window(all->wnd.x_ptr, all->wnd.wnd_ptr,
		all->img.img_ptr, 0, 0);
	mlx_destroy_image(all->wnd.x_ptr, all->img.img_ptr);
	all->img.img_ptr = mlx_new_image(all->wnd.x_ptr, all->img.width,
			all->img.height);
	all->img.addr = mlx_get_data_addr(all->img.img_ptr,
			&(all->img.bits_per_pixel), &(all->img.size_line),
			&(all->img.endian));
}

void	ft_draw_p_side_p(t_all *all)
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
			ft_draw_point(all, all->mat.p_side_p[i][j]);
			j++;
		}
		i++;
	}
	ft_draw_lines_rows(all, &(all->mat), all->mat.p_side_p);
	ft_draw_lines_cols(all, &(all->mat), all->mat.p_side_p);
	mlx_put_image_to_window(all->wnd.x_ptr, all->wnd.wnd_ptr,
		all->img.img_ptr, 0, 0);
	mlx_destroy_image(all->wnd.x_ptr, all->img.img_ptr);
	all->img.img_ptr = mlx_new_image(all->wnd.x_ptr, all->img.width,
			all->img.height);
	all->img.addr = mlx_get_data_addr(all->img.img_ptr,
			&(all->img.bits_per_pixel), &(all->img.size_line),
			&(all->img.endian));
}
