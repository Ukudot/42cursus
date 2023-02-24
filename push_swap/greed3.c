/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:17:13 by gpanico           #+#    #+#             */
/*   Updated: 2023/02/23 12:23:39 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_moves(int *moves, int move)
{
	int	ocs;
	int	i;

	ocs = 0;
	i = 1;
	while (i < moves[0])
	{
		if (moves[i] == move)
			ocs++;
		i++;
	}
	return (ocs);
}

void	ft_merge_moves(int **pseudo_moves, int move)
{
	int	*merged_moves;
	int	i;

	merged_moves = (int *) malloc(sizeof(int) * ((*pseudo_moves)[0] - 1));
	merged_moves[0] = (*pseudo_moves)[0] - 1;
	i = 1;
	while (i < merged_moves[0])
	{
		if ((*pseudo_moves)[i] != move && move)
		{
			merged_moves[i] = move;
			move = 0;
		}
		else
			merged_moves[i] = (*pseudo_moves)[i];
		i++;
	}
	free(*pseudo_moves);
	*pseudo_moves = merged_moves;
}

void	ft_optimize_moves(int **pseudo_moves)
{
	int	moves_counter[4];

	moves_counter[0] = ft_count_moves(*pseudo_moves, 0);
	moves_counter[1] = ft_count_moves(*pseudo_moves, 1);
	moves_counter[2] = ft_count_moves(*pseudo_moves, 3);
	moves_counter[3] = ft_count_moves(*pseudo_moves, 4);
	while (moves_counter[0] > 0 && moves_counter[1] > 0)
	{
		ft_merge_moves(pseudo_moves, 2);
		moves_counter[0]--;
		moves_counter[1]--;
	}
	while (moves_counter[2] > 0 && moves_counter[3] > 0)
	{
		ft_merge_moves(pseudo_moves, 5);
		moves_counter[2]--;
		moves_counter[3]--;
	}
}

int	*ft_pseudo_moves(t_stack stack_a, t_stack stack_b, int index)
{
	int	*pseudo_moves;
	int	value;

	pseudo_moves = (int *) malloc(sizeof(int) * 1);
	pseudo_moves[0] = 1;
	value = ft_move_as_first(stack_b, index, &pseudo_moves);
	ft_pick_position(stack_a, value, &pseudo_moves);
	ft_optimize_moves(&pseudo_moves);
	pseudo_moves = ft_update_moves(pseudo_moves, 6);
	return (pseudo_moves);
}

int	*top_gmove(t_stack stack_a, t_stack stack_b)
{
	int	i;
	int	*moves;
	int	*pseudo_moves;
	int	flag;

	moves = NULL;
	pseudo_moves = NULL;
	i = 0;
	flag = 0;
	while (i < stack_b.len)
	{
		if (i > stack_a.len / 2 && !(flag++))
			i = stack_b.len - stack_a.len / 2;
		pseudo_moves = ft_pseudo_moves(stack_a, stack_b, i);
		if (!moves || pseudo_moves[0] < moves[0])
		{
			free(moves);
			moves = pseudo_moves;
		}
		else
			free(pseudo_moves);
		i++;
	}
	return (moves);
}
