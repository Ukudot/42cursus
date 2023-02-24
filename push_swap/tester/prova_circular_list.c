#include "../push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_clist	*clist;
	int	i;

	clist = NULL;
	ft_clstadd_front(&clist, 10);
	ft_clstadd_front(&clist, 5);
	ft_clstadd_front(&clist, 1);
	i = 0;
	while (i < 3)
	{
		printf("adress %i:%p\n", i + 1, clist);
		printf("value %i:%i\n", i + 1, clist->value);
		printf("next %i:%p\n", i + 1, clist->next);
		clist = clist->next;
		i++;
	}
	printf("index 10:%i\n", ft_clst_index(clist, 10));
	printf("index 5:%i\n", ft_clst_index(clist, 5));
	printf("index 1:%i\n", ft_clst_index(clist, 1));
	i = 0;
	while (i < 1)
	{
		ft_clstdel_front(&clist);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		printf("adress %i:%p\n", i + 1, clist);
		printf("value %i:%i\n", i + 1, clist->value);
		printf("next %i:%p\n", i + 1, clist->next);
		clist = clist->next;
		i++;
	}
	i = 0;
	while (i < 2)
	{
		ft_clstdel_front(&clist);
		i++;
	}
}
