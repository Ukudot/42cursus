/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:05:12 by gpanico           #+#    #+#             */
/*   Updated: 2023/01/26 08:40:44 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define IDENTIFIERS "cspdiuxX%"
# include <stdarg.h>
# include <unistd.h>

char	*ft_strchr(const char *s, int c);
int		ft_is_identifier(const char *str, size_t *i);
int		ft_insert_identifier(const char *str, long item);
void	ft_init_fpointer(int (*putitems[9])(long item));
int		ft_putp(long item);
int		ft_putper(long item);
int		ft_putu(long item);
int		ft_putxx(long item);
int		ft_putx(long item);
int		ft_puti(long item);
int		ft_puts(long item);
int		ft_putc(long item);
void	ft_putunbr(unsigned int n, int *count);
void	ft_puthhex(unsigned int n, int *count);
void	ft_puthexp(unsigned long n, int *count);
void	ft_puthex(unsigned int n, int *count);
void	ft_putnbr(int n, int *count);
int		ft_printf(const char *str, ...);

#endif
