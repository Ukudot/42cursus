/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:40:05 by gpanico           #+#    #+#             */
/*   Updated: 2023/03/13 11:55:48 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_line_bresenham(t_all *all, int p1[2], int p2[2], long color[2])
{
	if (p1[0] < p2[0])
		ft_bresenham_low(all, p1, p2, color);
	else
	{
		ft_swap(&(color[0]), &(color[1]));
		ft_bresenham_low(all, p2, p1, color);
	}
}

void	ft_line_r_bresenham(t_all *all, int p1[2], int p2[2], long color[2])
{
	if (p1[1] < p2[1])
		ft_bresenham_high(all, p1, p2, color);
	else
	{
		ft_swap(&(color[0]), &(color[1]));
		ft_bresenham_high(all, p2, p1, color);
	}
}
