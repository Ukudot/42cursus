/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:52:06 by gpanico           #+#    #+#             */
/*   Updated: 2023/02/23 13:56:19 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_fpointer_checker(void (*fp[24])(t_stack *, t_stack *, int))
{
	fp[13] = &ft_ra;
	fp[17] = &ft_rb;
	fp[23] = &ft_rr;
	fp[2] = &ft_rra;
	fp[1] = &ft_rrb;
	fp[10] = &ft_rrr;
	fp[15] = &ft_pa;
	fp[18] = &ft_pb;
	fp[12] = &ft_sa;
	fp[16] = &ft_sb;
	fp[5] = &ft_ss;
}

void	ft_make_move_checker(t_stack *stack_a, t_stack *stack_b, int *moves)
{
	void	(*fp[24])(t_stack *, t_stack *, int);
	int		i;

	ft_init_fpointer_checker(fp);
	i = 1;
	while (i < moves[0])
	{
		(*fp[moves[i]])(stack_a, stack_b, 0);
		i++;
	}
	free(moves);
}

int	ft_forbidden(char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'r' || line[i] == 'p' || line[i] == 's')
		i++;
	else
		return (1);
	if (line[i] == 'a' || line[i] == 'b' || line[i] == line[i - 1])
		i++;
	else
		return (1);
	if (!line[i])
		return (0);
	if ((line[i] == line[i - 1] && line[i - 1] == 'r')
		|| (((line[i] == 'a') || (line[i] == 'b')) && line[i - 1] == 'r'))
		i++;
	else
		return (1);
	if (!line[i])
		return (0);
	return (1);
}

int	ft_hash(char *line)
{
	int	code;
	int	i;

	i = 0;
	code = 1;
	while (line[i])
	{
		code *= (int) line[i];
		i++;
	}
	code = (code % 100) / 4 - 1;
	return (code);
}

int	*ft_build_moves(int *moves)
{
	char	*line;

	moves = (int *) malloc(sizeof(int) * 1);
	moves[0] = 1;
	line = get_next_line(0);
	while (line)
	{
		if (ft_forbidden(line))
		{
			free(moves);
			write(2, "Error\n", 6);
			exit(1);
		}
		moves = ft_update_moves(moves, ft_hash(line));
		free(line);
		line = get_next_line(0);
	}
	return (moves);
}
