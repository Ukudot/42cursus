/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:12:29 by gpanico           #+#    #+#             */
/*   Updated: 2023/02/23 13:56:38 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	main(int argc, char *argv[])
{
	char			*input;
	t_stack			stack_a;
	t_stack			stack_b;
	static int		*moves;

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
	moves = ft_build_moves(moves);
	ft_make_move_checker(&stack_a, &stack_b, moves);
	if (ft_is_ordered(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_clst_free(&(stack_a.list));
	ft_clst_free(&(stack_b.list));
	return (0);
}
