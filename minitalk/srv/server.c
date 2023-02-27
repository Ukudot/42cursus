/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:07:25 by gpanico           #+#    #+#             */
/*   Updated: 2023/02/27 12:35:56 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"

int	ft_pow(int base, int exp)
{
	if (exp == 0)
		return (1);
	return (base * ft_pow(base, exp - 1));
}

void	ft_handler_usr(int signo, siginfo_t *info, void *unused)
{
	static int				i = -1;
	static unsigned char	c;

	unused = (void *)unused;
	if (++i < 7)
	{
		if (signo == SIGUSR2)
			c += ft_pow(2, i);
	}
	else
	{
		if (signo == SIGUSR2)
			c += ft_pow(2, i);
		if (c == 0)
		{
			kill(info->si_pid, SIGUSR1);
			write(1, "\n", 1);
		}
		write(1, &c, 1);
		c = 0;
		i = -1;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_handler = (void *)ft_handler_usr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("%i\n", getpid());
	while (1)
		pause();
}
