/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:58:37 by gpanico           #+#    #+#             */
/*   Updated: 2023/03/13 12:13:39 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_end(void *param)
{
	t_all	*all;

	all = (t_all *)param;
	ft_destroy_mat_p(all->mat.mat_p, all->mat.row);
	ft_destroy_mat_p(all->mat.p_top_p, all->mat.row);
	ft_destroy_mat_p(all->mat.p_front_p, all->mat.row);
	ft_destroy_mat_p(all->mat.p_side_p, all->mat.row);
	ft_destroy_mat_p(all->mat.sphere_p, all->mat.row);
	mlx_destroy_window(all->wnd.x_ptr, all->wnd.wnd_ptr);
	mlx_destroy_image(all->wnd.x_ptr, all->img.img_ptr);
	exit(0);
	return (0);
}

void	ft_sphere_control(int keycode, t_all *all)
{
	if (keycode == 49)
		ft_draw_sphere(all);
	else if (keycode == 35)
	{
		ft_s_rotate_x(all->wnd, &(all->mat), M_PI / 18);
		ft_draw_sphere(all);
	}
	else if (keycode == 31)
	{
		ft_s_rotate_y(all->wnd, &(all->mat), M_PI / 18);
		ft_draw_sphere(all);
	}
	else if (keycode == 34)
	{
		ft_s_rotate_z(all->wnd, &(all->mat), M_PI / 18);
		ft_draw_sphere(all);
	}
}

void	ft_mat_control(int keycode, t_all *all)
{
	void	(*rotate_s[6])(t_mat *, float);
	void	(*translate[14])(t_mat *, float);

	ft_init_rotate_s(rotate_s);
	ft_init_translate(translate);
	if (keycode == 49)
		ft_draw_mat_p(all);
	if (keycode - 83 >= 0 && keycode - 83 <= 5)
	{
		(*rotate_s[keycode - 83])(&(all->mat), M_PI / 18);
		ft_draw_mat_p(all);
	}
	else if ((keycode >= 0 && keycode <= 2) || keycode == 13)
	{
		(*translate[keycode])(&(all->mat), TRS);
		ft_draw_mat_p(all);
	}
}

int	ft_toggle_p(int keycode, int toggle_p, t_all *all)
{
	if (keycode == 3)
	{
		if (toggle_p)
			toggle_p = 0;
		else
			toggle_p = 1;
	}
	else if (keycode == 4)
	{
		if (toggle_p)
			toggle_p = 0;
		else
			toggle_p = 2;
	}
	else
	{
		if (toggle_p)
			toggle_p = 0;
		else
			toggle_p = 3;
	}
	if (!toggle_p)
		ft_draw_mat_p(all);
	return (toggle_p);
}
