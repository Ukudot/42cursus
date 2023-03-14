/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:18:27 by gpanico           #+#    #+#             */
/*   Updated: 2023/03/13 11:56:09 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	***ft_check_input_error(int argc, char *file, t_mat *mat)
{
	char	***map;

	ft_check_format(argc);
	ft_check_map_ext(file);
	ft_check_empty_map(file);
	map = ft_fill_map(file, mat);
	ft_check_map(map, mat);
	ft_check_elem(map, mat);
	return (map);
}

void	ft_check_format(int argc)
{
	if (argc != 2)
	{
		ft_printf("Usage error: ./fdf [map]\n");
		exit(1);
	}
}

void	ft_check_map_ext(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (i < 5 || ft_strncmp(&file[i - 4], ".fdf", 5))
	{
		ft_printf("File error: your map file hasn't \".fdf\" extension\n");
		exit(1);
	}
}

void	ft_check_empty_map(char *file)
{
	int		fd;
	int		r;
	char	buffer[1];

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("File error: not found/permission denied\n");
		exit(1);
	}
	r = read(fd, buffer, 1);
	close(fd);
	if (r == 0)
	{
		ft_printf("File error: empty file\n");
		exit(1);
	}
	else if (r < 0)
	{
		ft_printf("File error: read permission denied\n");
		exit(1);
	}
}
