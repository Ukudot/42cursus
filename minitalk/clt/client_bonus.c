/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpanico <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:07:18 by gpanico           #+#    #+#             */
/*   Updated: 2023/02/27 12:12:36 by gpanico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <unistd.h>
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"

void	ft_handler_usr(int signo)
{
	signo = (int) signo;
	ft_printf("The message is correctly sent.\n");
	exit(0);
}

void	ft_encoder(char *str, pid_t pid)
{
	int	i;

	while (*str)
	{
		i = -1;
		while (++i < 8)
		{
			if ((*str >> i) % 2)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(500);
		}
		str++;
	}
	i = -1;
	while (++i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(500);
	}
}

int	main(int argc, char *argv[])
{
	pid_t				pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Error, correct usage: [pid] [message]\n");
		exit(1);
	}
	sa.sa_handler = ft_handler_usr;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	pid = ft_atoi(argv[1]);
	ft_encoder(argv[2], pid);
	pause();
	return (0);
}
