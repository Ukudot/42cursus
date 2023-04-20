#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int	**ft_pipes(int **fds, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pipe(fds[i]);
		i++;
	}
	return (fds);
}

int	**ft_init_fds(int num)
{
	int	i;
	int	**fds;

	fds = (int **)malloc(sizeof(int *) * num);
	i = 0;
	while (i < num)
	{
		fds[i] = (int *)malloc(sizeof(int) * 2);
		i++;
	}
	return (fds);
}

int	*ft_init_pids(int num)
{
	int	*pids;

	pids = (int *)malloc(sizeof(int) * num);
	return (pids);
}

void	ft_close_pipes(int **fds, int read_fd, int write_fd, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (i != read_fd)
			close(fds[i][0]);
		if (i != write_fd)
			close(fds[i][1]);
		i++;
	}
	if (read_fd != -1)
		dup2(fds[read_fd][0], 0);
	if (write_fd != -1)
		dup2(fds[write_fd][1], 1);
}

void	ft_waitpid(int *pids, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		waitpid(pids[i], NULL, 0);
		i++;
	}
}

void	ft_child_exec(int *pids, int **fds, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pids[i] = fork();
		if (!pids[i])
		{
			if (i == num - 1)
				ft_close_pipes(fds, i - 1, -1, num);
			execve(cmd[0], &cmd[1], envp);
		}
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int	**fds;
	int	i;
	int	*pids;
	int	pid;
	int	pid2;
	int	pid3;
	int	r;
	char	*cmd1[] = {"cat", NULL};
	char	*cmd2[] = {"ls", NULL};
	char	*cmd3[] = {"grep", "ciao", NULL};
	char	buff[100];

	int	num = 2;
	fds = ft_init_fds(num);
	fds = ft_pipes(fds, num);
	pids = ft_init_pids(num + 1);
	ft_child_exec(pids, fds, num + 1);
	/*
	pids[0] = fork();
	if (!pids[0])
	{
		ft_close_pipes(fds, -1, 0, num);
		execve("/bin/cat", cmd1, envp);
	}
	pids[1] = fork();
	if (!pids[1])
	{
		ft_close_pipes(fds, 0, 1, num);
		execve("/bin/cat", cmd1, envp);
	}
	pids[2] = fork();
	if (!pids[2])
	{
		ft_close_pipes(fds, 1, -1, num);
		execve("/bin/ls", cmd2, envp);
	}
	*/
	ft_close_pipes(fds, -1, -1, num);
	ft_waitpid(pids, num);
	printf("hey\n");
	i = 0;
	while (i < num)
	{
		free(fds[i]);
		i++;
	}
	free(fds);
	free(pids);
	return (0);
}
