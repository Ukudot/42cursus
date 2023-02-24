/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 08:36:23 by gpanico           #+#    #+#             */
/*   Updated: 2023/02/23 13:29:14 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	*input;
	t_stack	stack_a;
	t_stack	stack_b;

	ft_init_stacks(&stack_a, &stack_b);
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	input = ft_parse_input(argc, argv);
	if (!input)
		return (1);
	ft_build_stack(&stack_a, input);
	free(input);
	ft_push_swap(&stack_a, &stack_b);
	ft_clst_free(&(stack_a.list));
	ft_clst_free(&(stack_b.list));
	return (0);
}
