/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 07:58:31 by gpanico           #+#    #+#             */
/*   Updated: 2023/03/13 12:20:40 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_zoom(int x, int y, t_all *all, float zoom)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->mat.row)
	{
		j = 0;
		while (j < all->mat.col)
		{
			all->mat.mat_p[i][j].x = (all->mat.mat_p[i][j].x - x) * zoom + x;
			all->mat.mat_p[i][j].y = (all->mat.mat_p[i][j].y - y) * zoom + y;
			all->mat.mat_p[i][j].z = all->mat.mat_p[i][j].z * zoom;
			j++;
		}
		i++;
	}
}
