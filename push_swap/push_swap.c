/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:17:18 by gpanico           #+#    #+#             */
/*   Updated: 2023/02/23 09:46:51 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_push_until(t_stack *stack_a, t_stack *stack_b, int size)
{
	while (stack_a->len > size)
		ft_pb(stack_a, stack_b, 1);
}

void	ft_move_min(t_stack *stack)
{
	int	index;

	index = ft_find_index(*stack, stack->min);
	while (stack->list->value != stack->min)
	{
		if (index < (stack->len) / 2 + (stack->len) % 2)
			ft_ra(stack, stack, 1);
		else
			ft_rra(stack, stack, 1);
	}
}

void	ft_push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_is_ordered(*stack_a))
	{
		ft_clst_free(&(stack_a->list));
		exit(0);
	}
	ft_push_until(stack_a, stack_b, 3);
	ft_three_number(stack_a);
	ft_greed(stack_a, stack_b);
	ft_move_min(stack_a);
}
