/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:48:36 by gpanico           #+#    #+#             */
/*   Updated: 2023/03/13 12:13:55 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init_rotate_s(void (*ft_s[6])(t_mat *, float))
{
	ft_s[0] = &ft_rotate_y;
	ft_s[1] = &ft_rotate_inverse_y;
	ft_s[2] = &ft_rotate_x;
	ft_s[3] = &ft_rotate_z;
	ft_s[4] = &ft_rotate_inverse_z;
	ft_s[5] = &ft_rotate_inverse_x;
}

void	ft_init_translate(void (*ft_t[150])(t_mat *, float))
{
	ft_t['a'] = &ft_translate_l; // 0 for mac
	ft_t['s'] = &ft_translate_d; // 1 for mac
	ft_t['d'] = &ft_translate_r; // 2 for mac
	ft_t['w'] = &ft_translate_u; // 13 for mac
}

int	ft_key_control(int keycode, void *param)
{
	t_all		*all;
	static int	toggle_s;
	static int	toggle_p;

	all = (t_all *)param;
	if (keycode >= '7' && keycode <= '9' && !(toggle_s % 2)) // 3, 4, 5 for mac
		toggle_p = ft_toggle_p(keycode, toggle_p, all);
	if (keycode == 48 && !toggle_p) // 49 for mac
		toggle_s += 1;
	if (toggle_s % 2 && !toggle_p)
		ft_sphere_control(keycode, all);
	else if (!(toggle_s % 2) && !toggle_p)
		ft_mat_control(keycode, all);
	else if (!(toggle_s % 2) && toggle_p == 1)
		ft_draw_p_top_p(all);
	else if (!(toggle_s % 2) && toggle_p == 2)
		ft_draw_p_front_p(all);
	else if (!(toggle_s % 2) && toggle_p == 3)
		ft_draw_p_side_p(all);
	if (keycode == 65307) //53 for mac
		ft_end((void *) all);
	return (0);
}

int	ft_mouse_control(int button, int x, int y, void *param)
{
	t_all	*all;

	all = (t_all *)param;
	if (button == 1)
	{
		ft_zoom(x, y, all, 1.1);
		ft_draw_mat_p(all);
	}
	else if (button == 3) //2 for mac
	{
		ft_zoom(x, y, all, 0.9);
		ft_draw_mat_p(all);
	}
	return (0);
}

void	ft_commands_hook(t_all	*all)
{
	mlx_hook(all->wnd.wnd_ptr, 17, 0, ft_end, (void *) all);
	mlx_mouse_hook(all->wnd.wnd_ptr, ft_mouse_control, (void *)all);
	mlx_key_hook(all->wnd.wnd_ptr, ft_key_control, (void *) all);
}
