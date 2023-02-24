/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:38:02 by gpanico           #+#    #+#             */
/*   Updated: 2023/02/20 09:13:05 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_stack *stack_a, t_stack *stack_b, int wrt)
{
	ft_rra(stack_a, stack_b, 0);
	ft_rrb(stack_a, stack_b, 0);
	if (wrt)
		write(1, "rrr\n", 4);
}
