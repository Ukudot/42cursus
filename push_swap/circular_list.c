/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 08:38:38 by gpanico           #+#    #+#             */
/*   Updated: 2023/02/16 10:03:38 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_clist	*ft_clstnew(int value)
{
	t_clist	*new;

	new = (t_clist *)malloc(sizeof(t_clist));
	new->value = value;
	new->next = NULL;
	return (new);
}

void	ft_clstadd_front(t_clist **list_head, int value)
{
	t_clist	*new;
	int		size;

	new = ft_clstnew(value);
	if (!(*list_head))
	{
		new->next = new;
		(*list_head) = new;
		return ;
	}
	new->next = (*list_head);
	size = ft_clst_size(*list_head);
	while (--size)
		*list_head = (*list_head)->next;
	(*list_head)->next = new;
	(*list_head) = new;
}

int	ft_clst_size(t_clist *list_head)
{
	int		size;
	t_clist	*end;

	if (!list_head)
		return (0);
	size = 1;
	end = list_head;
	list_head = list_head->next;
	while (list_head != end)
	{
		size++;
		list_head = list_head->next;
	}
	return (size);
}

void	ft_clstdel_front(t_clist **list_head)
{
	t_clist	*last;
	int		size;

	size = ft_clst_size(*list_head);
	if (size == 1)
	{
		free(*list_head);
		*list_head = NULL;
		return ;
	}
	last = (*list_head);
	while (--size)
		last = last->next;
	last->next = (*list_head)->next;
	free(*list_head);
	*list_head = last->next;
}

int	ft_min(t_clist *list)
{
	int	size;
	int	min;

	size = ft_clst_size(list);
	min = list->value;
	while (--size)
	{
		list = list->next;
		if (min > list->value)
			min = list->value;
	}
	return (min);
}
