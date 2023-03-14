/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:58:37 by gpanico           #+#    #+#             */
/*   Updated: 2023/03/13 11:56:38 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_end(void *param)
{
	t_all	*all;

	all = (t_all *)param;
	ft_destroy_mat_p(all->mat.mat_p, all->mat.row);
	mlx_destroy_window(all->wnd.x_ptr, all->wnd.wnd_ptr);
	mlx_destroy_image(all->wnd.x_ptr, all->img.img_ptr);
	exit(0);
	return (0);
}
