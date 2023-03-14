/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:27:49 by gpanico           #+#    #+#             */
/*   Updated: 2023/03/13 11:57:11 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

long	ft_color_line(long col1, long col2, float x, float l)
{
	long	c_col1[3];
	long	c_col2[3];
	long	n_col;
	long	n_col_c[3];
	int		i;

	c_col1[0] = col1 / (long) pow(16, 4);
	c_col1[1] = (col1 / (long) pow(16, 2)) % (long) pow(16, 2);
	c_col1[2] = col1 % (long) pow(16, 2);
	c_col2[0] = col2 / (long) pow(16, 4);
	c_col2[1] = (col2 / (long) pow(16, 2)) % (long) pow(16, 2);
	c_col2[2] = col2 % (long) pow(16, 2);
	i = 0;
	while (i < 3)
	{
		n_col_c[i] = (c_col1[i] * (l - x) / l + c_col2[i] * x / l);
		i++;
	}
	n_col = n_col_c[0] * (long) pow(16, 4) + n_col_c[1] * (long) pow(16, 2)
		+ n_col_c[2];
	return (n_col);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + x * (img->bits_per_pixel / 8) + y * img->size_line;
	*(unsigned int *)pixel = color;
}
