/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:45:32 by gpanico           #+#    #+#             */
/*   Updated: 2023/02/23 08:54:08 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three_number(t_stack *stack_a)
{
	int	index;

	index = ft_clst_index(stack_a->list, stack_a->max);
	if (index == 0)
		ft_ra(stack_a, stack_a, 1);
	else if (index == 1)
		ft_rra(stack_a, stack_a, 1);
	if (stack_a->list->value > stack_a->list->next->value)
		ft_sa(stack_a, stack_a, 1);
}
