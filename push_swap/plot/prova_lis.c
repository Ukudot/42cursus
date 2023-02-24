#include "../push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_clist	*lis;
	t_stack	stack;
	t_stack	stack2;
	int	num[] = {349, 210, 483, 193, 156, 159, 354, 243, 105, 178, 456, 77, 350, 87, 340, 298, 63, 180, 150, 223, 286, 424, 384, 398, 316, 92, 62, 224, 2, 437, 111, 357, 263, 61, 400, 301, 310, 269, 244, 288, 422, 367, 322, 26, 194, 492, 403, 48, 71, 373, 423, 493, 226, 66, 406, 82, 55, 67, 358, 369, 15, 330, 84, 319, 157, 114, 181, 36, 365, 128, 51, 490, 208, 78, 363, 54, 188, 16, 31, 201, 59, 431, 379, 486, 408, 471, 148, 489, 320, 293, 331, 267, 326, 173, 228, 256, 241, 339, 137, 419};
	int	i;
	int	index;
	int	*pseudo_moves;

	stack.list = NULL;
	stack.len = 0;
	stack.min = 2147483647;
	stack.max = -2147483648;
	stack2.list = NULL;
	stack2.len = 0;
	stack2.min = 2147483647;
	stack2.max = -2147483648;
	i = argc - 2;
	while (i > 0)
	{
		//printf("%i\n", ft_atoi(num[i]));
		ft_clstadd_front(&(stack.list),(int) ft_atoi(argv[i]));
		ft_update(&stack);
		i--;
		stack.len++;
	}
	//ft_print_stack(&stack);
	//lis = ft_find_lis(&stack);
	//ft_print_clist(lis);
	//ft_push_others(&stack, &stack2, lis);
	//printf("stack:\n");
	//ft_print_stack(&stack);
	//printf("stack2:\n");
	//ft_print_stack(&stack2);

	//index = ft_find_index(stack, -23);
	//printf("number|index: -23|%d\n", index);
	//index = ft_find_index(stack, 17);
	//printf("number|index: 17|%d\n", index);
	//index = ft_find_index(stack, 8);
	//printf("number|index: 8|%d\n", index);
	//index = ft_find_index(stack, 14);
	//printf("number|index: 14|%d\n", index);

	//pseudo_moves = top_gmove(stack, stack2);
	//printf("pseudo_move[0]: %i\n", pseudo_moves[0]);
	//i = 1;
	//while ( i < pseudo_moves[0])
	//{
	//	printf("move: %i\n", pseudo_moves[i]);
	//	i++;
	//}
	//free(pseudo_moves);
	if (argv[argc - 1][0] == 't')
	{
		ft_push_until(&stack, &stack2, 3);
		printf("cioa\n");
		ft_three_number(&stack);
		printf("cioa\n");
		ft_greed(&stack, &stack2);
		printf("cioa\n");
	}
	else
		ft_push_swap(&stack, &stack2);
	//printf("stack:\n");
	//ft_print_stack(&stack);
	//printf("stack2:\n");
	//ft_print_stack(&stack2);

	ft_free_stack(&stack);
	ft_free_stack(&stack2);
	//ft_clst_free(&lis);
}
