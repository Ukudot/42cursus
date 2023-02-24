#include "../push_swap.h"
#include <stdio.h>

void	ft_print_clist(t_clist *list)
{
	int	size;

	printf("List:\n");
	size = ft_clst_size(list);
	while(size)
	{
		printf("\tadress: %p\n", list);
		printf("\tvalue: %d\n", list->value);
		printf("\tnext: %p\n", list->next);
		list = list->next;
		size--;
	}
}

void	ft_print_stack(t_stack *stack)
{
	printf("Len: %i\n", stack->len);
	printf("Min: %i\n", stack->min);
	printf("Max: %i\n", stack->max);
	ft_print_clist(stack->list);
}
/*
int	main(void)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.list = NULL;
	stack_a.len = 0;
	stack_a.min = 1;
	stack_a.max = 1;
	stack_b.list = NULL;
	stack_b.len = 0;
	stack_b.min = 5;
	stack_b.max = 5;
	ft_clstadd_front(&(stack_a.list), 1);
	ft_update(&stack_a, 1);
	stack_a.len++;
	ft_clstadd_front(&(stack_a.list), 2);
	ft_update(&stack_a, 2);
	stack_a.len++;
	ft_clstadd_front(&(stack_a.list), 3);
	ft_update(&stack_a, 3);
	stack_a.len++;
	ft_clstadd_front(&(stack_a.list), 4);
	ft_update(&stack_a, 4);
	stack_a.len++;

	ft_clstadd_front(&(stack_b.list), 5);
	ft_update(&stack_b, 5);
	stack_b.len++;
	ft_clstadd_front(&(stack_b.list), 6);
	ft_update(&stack_b, 6);
	stack_b.len++;
	ft_clstadd_front(&(stack_b.list), 7);
	ft_update(&stack_b, 7);
	stack_b.len++;
	ft_clstadd_front(&(stack_b.list), 8);
	ft_update(&stack_b, 8);
	stack_b.len++;

	printf("Stack_a:\n");
	ft_print_stack(&stack_a);
	ft_sa(&stack_a, 0);
	printf("Stack_a:\n");
	ft_print_stack(&stack_a);
	ft_sa(&stack_a, 0);
	printf("Stack_a:\n");
	ft_print_stack(&stack_a);
	printf("Stack_b:\n");
	ft_print_stack(&stack_b);
	ft_sb(&stack_b, 0);
	printf("Stack_b:\n");
	ft_print_stack(&stack_b);
	ft_sb(&stack_b, 0);
	printf("Stack_b:\n");
	ft_print_stack(&stack_b);
	ft_ss(&stack_a ,&stack_b, 0);
	printf("Stack_a:\n");
	ft_print_stack(&stack_a);
	printf("Stack_b:\n");
	ft_print_stack(&stack_b);
	ft_ss(&stack_a ,&stack_b, 0);
	printf("Stack_a:\n");
	ft_print_stack(&stack_a);
	printf("Stack_b:\n");
	ft_print_stack(&stack_b);	
	ft_pa(&stack_a ,&stack_b, 0);
	printf("Stack_a:\n");
	ft_print_stack(&stack_a);
	printf("Stack_b:\n");
	ft_print_stack(&stack_b);
	ft_pa(&stack_a ,&stack_b, 0);
	printf("Stack_a:\n");
	ft_print_stack(&stack_a);
	printf("Stack_b:\n");
	ft_print_stack(&stack_b);
	ft_pa(&stack_a ,&stack_b, 0);
	printf("Stack_a:\n");
	ft_print_stack(&stack_a);
	printf("Stack_b:\n");
	ft_print_stack(&stack_b);
	ft_pa(&stack_a ,&stack_b, 0);
	printf("Stack_a:\n");
	ft_print_stack(&stack_a);
	printf("Stack_b:\n");
	ft_print_stack(&stack_b);
	ft_pb(&stack_a ,&stack_b, 0);
	printf("Stack_a:\n");
	ft_print_stack(&stack_a);
	ft_pb(&stack_a ,&stack_b, 0);
	printf("Stack_a:\n");
	ft_print_stack(&stack_a);
	printf("Stack_b:\n");
	ft_print_stack(&stack_b);
	ft_pb(&stack_a ,&stack_b, 0);
	printf("Stack_a:\n");
	ft_print_stack(&stack_a);
	printf("Stack_b:\n");
	ft_print_stack(&stack_b);
	ft_ra(&stack_a, 0);
	printf("Stack_a:\n");
	ft_print_stack(&stack_a);
	ft_rb(&stack_b, 0);
	printf("Stack_b:\n");
	ft_print_stack(&stack_b);
	ft_rra(&stack_a, 0);
	printf("Stack_a:\n");
	ft_print_stack(&stack_a);
	ft_rrb(&stack_b, 0);
	printf("Stack_b:\n");
	ft_print_stack(&stack_b);
	ft_rrr(&stack_a, &stack_b, 0);
	printf("Stack_a:\n");
	ft_print_stack(&stack_a);
	printf("Stack_b:\n");
	ft_print_stack(&stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}*/
