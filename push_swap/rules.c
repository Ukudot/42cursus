/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 08:42:04 by gpanico           #+#    #+#             */
/*   Updated: 2023/02/20 16:43:14 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stack_a, t_stack *stack_b, int wrt)
{
	t_clist	*second;
	int		tmp;

	(void)stack_b;
	second = stack_a->list->next;
	tmp = second->value;
	second->value = stack_a->list->value;
	stack_a->list->value = tmp;
	if (wrt)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack *stack_a, t_stack *stack_b, int wrt)
{
	t_clist	*second;
	int		tmp;

	(void)stack_a;
	second = stack_b->list->next;
	tmp = second->value;
	second->value = stack_b->list->value;
	stack_b->list->value = tmp;
	if (wrt)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b, int wrt)
{
	ft_sa(stack_a, stack_b, 0);
	ft_sb(stack_a, stack_b, 0);
	if (wrt)
		write(1, "ss\n", 3);
}

void	ft_pb(t_stack *stack_a, t_stack *stack_b, int wrt)
{
	int	value;

	value = stack_a->list->value;
	ft_clstdel_front(&(stack_a->list));
	if (stack_a->len == 1)
	{
		stack_a->min = 2147483647;
		stack_a->max = -2147483648;
	}
	else
		ft_update(stack_a);
	stack_a->len--;
	ft_clstadd_front(&(stack_b->list), value);
	ft_update(stack_b);
	stack_b->len++;
	if (wrt)
		write(1, "pb\n", 3);
}

void	ft_pa(t_stack *stack_a, t_stack *stack_b, int wrt)
{
	int	value;

	value = stack_b->list->value;
	ft_clstdel_front(&(stack_b->list));
	if (stack_b->len == 1)
	{
		stack_b->min = 2147483647;
		stack_b->max = -2147483648;
	}
	else
		ft_update(stack_b);
	stack_b->len--;
	ft_clstadd_front(&(stack_a->list), value);
	ft_update(stack_a);
	stack_a->len++;
	if (wrt)
		write(1, "pa\n", 3);
}
