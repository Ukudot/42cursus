#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		*moves;
	int		i;
	char	*line;

	line = malloc(1);
	moves = ft_build_moves(moves, line);
	i = 0;
	free(moves);
	free(line);
	return (0);
}
