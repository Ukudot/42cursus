/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:17:13 by gpanico           #+#    #+#             */
/*   Updated: 2023/02/23 13:26:02 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_fpointer(void (*fp[24])(t_stack *, t_stack *, int))
{
	fp[0] = &ft_ra;
	fp[1] = &ft_rb;
	fp[2] = &ft_rr;
	fp[3] = &ft_rra;
	fp[4] = &ft_rrb;
	fp[5] = &ft_rrr;
	fp[6] = &ft_pa;
	fp[7] = &ft_pb;
	fp[8] = &ft_sa;
	fp[9] = &ft_sb;
	fp[10] = &ft_ss;
}

void	ft_make_moves(t_stack *stack_a, t_stack *stack_b, int *moves)
{
	void	(*fp[24])(t_stack *, t_stack *, int);
	int		i;

	ft_init_fpointer(fp);
	i = 1;
	while (i < moves[0])
	{
		(*fp[moves[i]])(stack_a, stack_b, 1);
		i++;
	}
}

void	ft_greed(t_stack *stack_a, t_stack *stack_b)
{
	int	*moves;

	while (stack_b->len)
	{
		moves = top_gmove(*stack_a, *stack_b);
		ft_make_moves(stack_a, stack_b, moves);
		free(moves);
	}
}
