/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 08:38:38 by gpanico           #+#    #+#             */
/*   Updated: 2023/02/22 12:20:14 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_max(t_clist *list)
{
	int	size;
	int	max;

	size = ft_clst_size(list);
	max = list->value;
	while (--size)
	{
		list = list->next;
		if (max < list->value)
			max = list->value;
	}
	return (max);
}

void	ft_clst_last(t_clist **list)
{
	int	size;

	size = ft_clst_size(*list);
	while (--size)
		(*list) = (*list)->next;
}

int	ft_in_clist(t_clist *list, int value)
{
	int	size;

	size = ft_clst_size(list);
	while (size)
	{
		if (value == list->value)
			return (1);
		list = list->next;
		size--;
	}
	return (0);
}

void	ft_clst_free(t_clist **list)
{
	int	size;

	if (!(*list))
		return ;
	size = ft_clst_size(*list);
	while (size)
	{
		ft_clstdel_front(list);
		size--;
	}
	*list = NULL;
}

int	ft_clst_index(t_clist *list, int value)
{
	int	index;

	index = 0;
	while (list->value != value)
	{
		list = list->next;
		index++;
	}
	return (index);
}
