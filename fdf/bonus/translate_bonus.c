/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:09:34 by gpanico           #+#    #+#             */
/*   Updated: 2023/03/13 12:19:43 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_translate_u(t_mat *mat, float trs)
{
	int	i;
	int	j;

	i = 0;
	while (i < mat->row)
	{
		j = 0;
		while (j < mat->col)
		{
			mat->mat_p[i][j].y -= trs;
			j++;
		}
		i++;
	}
}

void	ft_translate_d(t_mat *mat, float trs)
{
	int	i;
	int	j;

	i = 0;
	while (i < mat->row)
	{
		j = 0;
		while (j < mat->col)
		{
			mat->mat_p[i][j].y += trs;
			j++;
		}
		i++;
	}
}

void	ft_translate_r(t_mat *mat, float trs)
{
	int	i;
	int	j;

	i = 0;
	while (i < mat->row)
	{
		j = 0;
		while (j < mat->col)
		{
			mat->mat_p[i][j].x += trs;
			j++;
		}
		i++;
	}
}

void	ft_translate_l(t_mat *mat, float trs)
{
	int	i;
	int	j;

	i = 0;
	while (i < mat->row)
	{
		j = 0;
		while (j < mat->col)
		{
			mat->mat_p[i][j].x -= trs;
			j++;
		}
		i++;
	}
}
