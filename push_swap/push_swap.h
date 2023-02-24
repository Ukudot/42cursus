/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 08:38:42 by gpanico           #+#    #+#             */
/*   Updated: 2023/02/23 14:12:12 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 1

// circular list
typedef struct s_clist
{
	int				value;
	struct s_clist	*next;
}	t_clist;
// stack
typedef struct s_stack
{
	t_clist	*list;
	int		len;
	int		min;
	int		max;
}	t_stack;
// circular list functions
t_clist	*ft_clstnew(int value);
void	ft_clstadd_front(t_clist **list_head, int value);
void	ft_clstdel_front(t_clist **list_head);
int		ft_clst_size(t_clist *list_head);
int		ft_min(t_clist *list);
int		ft_max(t_clist *list);
void	ft_clst_last(t_clist **list_head);
int		ft_in_clist(t_clist *list, int value);
void	ft_clst_free(t_clist **list);
int		ft_clst_index(t_clist *list, int value);
// stack functions
int		ft_is_ordered(t_stack stack);
void	ft_update(t_stack *stack);
void	ft_free_stack(t_stack *stack);
// rules
void	ft_sa(t_stack *stack_a, t_stack *stack_b, int wrt);
void	ft_sb(t_stack *stack_a, t_stack *stack_b, int wrt);
void	ft_ss(t_stack *stack_a, t_stack *stack_b, int wrt);
void	ft_pa(t_stack *stack_a, t_stack *stack_b, int wrt);
void	ft_pb(t_stack *stack_a, t_stack *stack_b, int wrt);
void	ft_ra(t_stack *stack_a, t_stack *stack_b, int wrt);
void	ft_rb(t_stack *stack_a, t_stack *stack_b, int wrt);
void	ft_rr(t_stack *stack_a, t_stack *stack_b, int wrt);
void	ft_rra(t_stack *stack_a, t_stack *stack_b, int wrt);
void	ft_rrb(t_stack *stack_a, t_stack *stack_b, int wrt);
void	ft_rrr(t_stack *stack_a, t_stack *stack_b, int wrt);
// greed algorithm
int		*ft_update_moves(int *pseudo_moves, int move);
int		ft_check_bounds(t_stack stack_a, int value, int *index);
int		ft_find_index(t_stack stack_a, int value);
void	ft_pick_position(t_stack stack_a, int value, int **pseudo_moves);
int		ft_move_as_first(t_stack stack_b, int index, int **pseudo_moves);
int		*ft_pseudo_moves(t_stack stack_a, t_stack stack_b, int index);
int		*top_gmove(t_stack stack_a, t_stack stack_b);
void	ft_greed(t_stack *stack_a, t_stack *stack_b);
int		ft_count_moves(int *moves, int move);
void	ft_merge_moves(int **pseudo_moves, int move);
void	ft_optimize_moves(int **pseudo_moves);
void	ft_init_fpointer(void (*fp[24])(t_stack *, t_stack *, int));
void	ft_make_moves(t_stack *stack_a, t_stack *stack_b, int *moves);
// push_swap functions
void	ft_push_until(t_stack *stack_a, t_stack *stack_b, int size);
void	ft_three_number(t_stack *stack_a);
void	ft_move_min(t_stack *stack);
void	ft_push_swap(t_stack *stack_a, t_stack *stack_b);
//input
int		ft_isspace(int n);
long	ft_atoi(char *num);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_check_double(char *str);
int		ft_is_digit(char n);
int		ft_check_digit(char *str);
char	*ft_parse_input(int argc, char **argv);
int		ft_insert_number(t_stack *stack_a, char *num);
void	ft_build_stack(t_stack *stack_a, char *input);
// main
void	ft_init_stacks(t_stack *stack_a, t_stack *stack_b);
// bonus
void	ft_init_fpointer_checker(void (*fp[24])(t_stack *, t_stack *, int));
void	ft_make_move_checker(t_stack *stack_a, t_stack *stack_b, int *moves);
int		ft_forbidden(char *line);
int		ft_hash(char *line);
int		*ft_build_moves(int *moves);
// get next line
int		ft_check_error(int r, char *str);
char	*ft_strjoin_get(char *str, char *buffer);
void	ft_move_buffer(char *buffer);
char	*ft_realloc(char *str, char *buffer);
char	*get_next_line(int fd);

#endif
