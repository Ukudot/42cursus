/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:48:36 by gpanico           #+#    #+#             */
/*   Updated: 2023/03/13 11:56:24 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_key_control(int keycode, void *param)
{
	t_all		*all;
	static int	toggle_s;
	static int	toggle_p;

	all = (t_all *)param;
	if (keycode == 53)
		ft_end((void *) all);
	return (0);
}

void	ft_commands_hook(t_all	*all)
{
	mlx_hook(all->wnd.wnd_ptr, 17, 0, ft_end, (void *) all);
	mlx_key_hook(all->wnd.wnd_ptr, ft_key_control, (void *) all);
}
