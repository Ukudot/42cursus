/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:13:18 by gpanico           #+#    #+#             */
/*   Updated: 2023/02/23 13:29:03 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stacks(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->len = 0;
	stack_b->len = 0;
	stack_a->min = 2147483647;
	stack_a->max = -2147483648;
	stack_a->list = NULL;
	stack_b->min = 2147483647;
	stack_b->max = -2147483648;
	stack_b->list = NULL;
}

int	ft_is_ordered(t_stack stack)
{
	int	value;

	value = stack.list->value;
	stack.list = stack.list->next;
	while (--stack.len)
	{
		if (value > stack.list->value)
			return (0);
		value = stack.list->value;
		stack.list = stack.list->next;
	}
	return (1);
}

void	ft_update(t_stack *stack)
{
	stack->min = ft_min(stack->list);
	stack->max = ft_max(stack->list);
}

void	ft_free_stack(t_stack *stack)
{
	while (stack->len)
	{
		ft_clstdel_front(&(stack->list));
		stack->len--;
	}
}
