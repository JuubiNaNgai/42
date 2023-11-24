/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:07:33 by aleite-b          #+#    #+#             */
/*   Updated: 2023/11/21 13:46:01 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_command(int in_fd, int out_fd, char *command, char **envp)
{
	pid_t		pid;
	char		**splitted_cmds;

	pid = fork();
	if (pid == -1)
	{
		printf("d");
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		printf("c");
		if (in_fd != STDIN_FILENO)
		{
			dup2(in_fd, STDIN_FILENO);
			close(in_fd);
		}
		if (out_fd != STDOUT_FILENO)
		{
			dup2(out_fd, STDOUT_FILENO);
			close(out_fd);
		}
		splitted_cmds = ft_split(command, ' ');
		execve(command, splitted_cmds, envp);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	num_commands;
	int	*pipes;
	int	i;
	int	in_fd;
	int	out_fd;

	if (argc < 2)
	{
		perror("./pipex infile cmd1 cmd2 . . . cmdn outfile");
		exit(EXIT_FAILURE);
	}
	num_commands = argc - 3;
	pipes = malloc(sizeof(int) * 2 * (num_commands - 1));
	i = 0;
	while (i < num_commands - 1)
	{
		if (pipe(pipes + i * 2) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		if (i == 0)
		{
			in_fd = open(argv[1], O_RDONLY);
			if (in_fd == -1)
			{
				perror("open input file");
				exit(EXIT_FAILURE);
			}
		}
		else
			in_fd = pipes[(i - 1) * 2];
		if (i == num_commands - 1)
		{
			out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 00777);
			if (out_fd == -1)
			{
				perror("open output file");
				exit(EXIT_FAILURE);
			}
		}
		else
			out_fd = pipes[i * 2 + 1];
		execute_command(in_fd, out_fd, argv[i + 2], envp);
		i++;
	}
	i = 0;
	while (i < num_commands - 1)
	{
		close(pipes[i * 2]);
		close(pipes[i * 2 + 1]);
		waitpid(-1, NULL, 0);
		i++;
	}
	waitpid(-1, NULL, 0);
	free(pipes);
	return (0);
}
