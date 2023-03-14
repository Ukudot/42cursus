/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:18:34 by gpanico           #+#    #+#             */
/*   Updated: 2023/03/13 11:58:05 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	***ft_fill_map(char *file, t_mat *mat)
{
	char	***map;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	mat->row = 1;
	map = (char ***)malloc(sizeof(char **) * mat->row);
	line = get_next_line(fd);
	map[mat->row - 1] = ft_split(line, ' ');
	free(line);
	while (map[mat->row - 1])
	{
		(mat->row)++;
		map = (char ***)ft_realloc((void *)map, sizeof(char **),
				mat->row -1, mat->row);
		line = get_next_line(fd);
		map[mat->row - 1] = ft_split(line, ' ');
		free(line);
	}
	mat->row -= 1;
	close(fd);
	return (map);
}

void	ft_destroy_map(char ***map, int row)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (map[i][j])
		{
			free(map[i][j]);
			j++;
		}
		free(map[i]);
		i++;
	}
	free(map);
}
