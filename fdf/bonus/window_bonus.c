/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:16:46 by gpanico           #+#    #+#             */
/*   Updated: 2023/03/13 12:20:12 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"

void	ft_init_window(t_all *all)
{
	all->wnd.x_ptr = mlx_init();
	all->wnd.wnd_ptr = mlx_new_window(all->wnd.x_ptr, all->wnd.width,
			all->wnd.height, "fdf");
	all->img.img_ptr = mlx_new_image(all->wnd.x_ptr, all->wnd.width,
			all->wnd.height);
	all->img.addr = mlx_get_data_addr(all->img.img_ptr,
			&(all->img.bits_per_pixel), &(all->img.size_line),
			&(all->img.endian));
	ft_first_image(all);
}

void	ft_first_image(t_all *all)
{
	int	i;

	i = 0;
	ft_rotate_x(&(all->mat), (double) M_PI / 2);
	ft_rotate_y(&(all->mat), (double) -M_PI / 4);
	ft_rotate_x(&(all->mat), -atan(1 / sqrt(2)));
	ft_draw_mat_p(all);
}
