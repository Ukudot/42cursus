/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:38:02 by gpanico           #+#    #+#             */
/*   Updated: 2023/02/20 09:12:34 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *stack_a, t_stack *stack_b, int wrt)
{
	(void) stack_b;
	stack_a->list = stack_a->list->next;
	if (wrt)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack *stack_a, t_stack *stack_b, int wrt)
{
	(void) stack_a;
	stack_b->list = stack_b->list->next;
	if (wrt)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b, int wrt)
{
	ft_ra(stack_a, stack_b, 0);
	ft_rb(stack_a, stack_b, 0);
	if (wrt)
		write(1, "rr\n", 3);
}

void	ft_rra(t_stack *stack_a, t_stack *stack_b, int wrt)
{
	(void) stack_b;
	ft_clst_last(&(stack_a->list));
	if (wrt)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *stack_a, t_stack *stack_b, int wrt)
{
	(void) stack_a;
	ft_clst_last(&(stack_b->list));
	if (wrt)
		write(1, "rrb\n", 4);
}
