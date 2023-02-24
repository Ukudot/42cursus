/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:12:21 by gpanico           #+#    #+#             */
/*   Updated: 2023/02/23 12:15:11 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_insert_number(t_stack *stack_a, char *num)
{
	long	n;

	n = ft_atoi(num);
	if (n < -2147483648 || n > 2147483647)
		return (1);
	if (ft_in_clist(stack_a->list, (int) n))
		return (1);
	ft_clstadd_front(&(stack_a->list), (int) n);
	ft_update(stack_a);
	stack_a->len++;
	return (0);
}

void	ft_build_stack(t_stack *stack_a, char *input)
{
	int	len;

	len = ft_strlen(input);
	while (--len >= 0)
	{
		while (len >= 0 && !ft_is_digit(input[len]))
			len--;
		while (len >= 0 && ft_is_digit(input[len]))
			len--;
		if (len >= 0 && ft_insert_number(stack_a, &input[len]))
		{
			free(input);
			ft_clst_free(&(stack_a->list));
			write(2, "Error\n", 6);
			exit(1);
		}
	}
}
