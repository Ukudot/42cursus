/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:32:08 by gpanico           #+#    #+#             */
/*   Updated: 2023/02/01 09:08:58 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_error(int r, char *str)
{
	if (r < 0)
	{
		if (str)
			free(str);
		return (1);
	}
	return (0);
}

char	*ft_strjoin(char *str, char *buffer)
{
	int		len;
	char	*new;

	len = 0;
	while (str[len])
		len++;
	new = (char *) malloc((len + 2) * sizeof(char));
	if (!new)
	{
		free(str);
		return (NULL);
	}
	new[len + 1] = 0;
	new[len] = buffer[0];
	len--;
	while (len >= 0)
	{
		new[len] = str[len];
		len--;
	}
	if (str)
		free(str);
	return (new);
}

void	ft_movebuffer(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE - 1)
	{
		buffer[i] = buffer[i + 1];
		if (!buffer[i])
			break ;
		i++;
	}
	buffer[i] = 0;
}

char	*ft_realloc(char *str, char *buffer)
{
	char	*new;

	if (!str)
	{
		new = (char *) malloc(2 * sizeof(char));
		if (!new)
			return (NULL);
		new[0] = buffer[0];
		new[1] = 0;
	}
	else
		new = ft_strjoin(str, buffer);
	ft_movebuffer(buffer);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*str;
	int			r;

	r = 1;
	str = NULL;
	while (r)
	{
		while (buffer[0] != '\n' && buffer[0])
		{
			str = ft_realloc(str, buffer);
			if (!str)
				return (NULL);
		}
		if (buffer[0] == '\n')
		{
			str = ft_realloc(str, buffer);
			break ;
		}
		r = read(fd, buffer, BUFFER_SIZE);
		if (ft_check_error(r, str))
			return (NULL);
	}
	return (str);
}
