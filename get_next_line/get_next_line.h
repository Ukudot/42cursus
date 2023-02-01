/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:29:46 by gpanico           #+#    #+#             */
/*   Updated: 2023/01/27 15:46:53 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

int		ft_check_error(int r, char *str);
char	*ft_strjoin(char *str, char *buffer);
void	ft_movebuffer(char *buffer);
char	*ft_realloc(char *str, char *buffer);
char	*get_next_line(int fd);

#endif
