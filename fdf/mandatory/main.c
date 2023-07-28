/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:19:07 by gpanico           #+#    #+#             */
/*   Updated: 2023/03/13 11:57:53 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char *argv[])
{
	t_all	all;
	char	***map;

	all.wnd.height = HEIGHT;
	all.img.height = HEIGHT;
	all.wnd.width = WIDTH;
	all.img.width = WIDTH;
	map = ft_check_input_error(argc, argv[1], &(all.mat));
	ft_map_to_mat(map, &(all.mat), all.wnd);
	ft_normalize(&(all.mat), all.wnd);
	ft_init_window(&all);
	ft_commands_hook(&all);
	mlx_loop(all.wnd.x_ptr);
	return (0);
}
