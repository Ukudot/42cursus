/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:17:13 by gpanico           #+#    #+#             */
/*   Updated: 2023/02/23 10:37:50 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_update_moves(int *pseudo_moves, int move)
{
	int	*new_moves;
	int	i;

	new_moves = (int *) malloc(sizeof(int) * (pseudo_moves[0] + 1));
	new_moves[0] = pseudo_moves[0] + 1;
	i = 0;
	while (++i < pseudo_moves[0])
		new_moves[i] = pseudo_moves[i];
	new_moves[i] = move;
	free(pseudo_moves);
	return (new_moves);
}

int	ft_check_bounds(t_stack stack_a, int value, int *index)
{
	if (value < stack_a.min || value > stack_a.max)
	{	
		index[0] = ft_clst_index(stack_a.list, stack_a.min);
		return (1);
	}
	return (0);
}

int	ft_find_index(t_stack stack_a, int value)
{
	int	index[2];
	int	i;

	if (ft_check_bounds(stack_a, value, index))
		return (index[0]);
	index[0] = 0;
	index[1] = 2147483647;
	i = 0;
	while (i < stack_a.len)
	{
		if (value < (stack_a.list)->value
			&& (stack_a.list)->value < index[1])
		{
			index[0] = i;
			index[1] = (stack_a.list)->value;
		}
		i++;
		stack_a.list = (stack_a.list)->next;
	}
	return (index[0]);
}

int	ft_move_as_first(t_stack stack_b, int index, int **pseudo_moves)
{
	while (index && index != stack_b.len)
	{
		if (index < (stack_b.len / 2 + stack_b.len % 2))
		{
			ft_rb(&stack_b, &stack_b, 0);
			*pseudo_moves = ft_update_moves(*pseudo_moves, 1);
			index--;
		}
		else
		{
			ft_rrb(&stack_b, &stack_b, 0);
			*pseudo_moves = ft_update_moves(*pseudo_moves, 4);
			index++;
		}
	}
	return (stack_b.list->value);
}

void	ft_pick_position(t_stack stack_a, int value, int **pseudo_moves)
{
	int	index;

	index = ft_find_index(stack_a, value);
	while (index && index != stack_a.len)
	{
		if (index < (stack_a.len / 2 + stack_a.len % 2))
		{
			*pseudo_moves = ft_update_moves(*pseudo_moves, 0);
			index--;
		}
		else
		{
			*pseudo_moves = ft_update_moves(*pseudo_moves, 3);
			index++;
		}
	}
}
